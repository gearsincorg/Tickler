/**
  File Name:
    main.c
    (c) 2019 Phil Malone:  FlipIt  &  FlyDayz
 * 
 * Rev  Date        Comment
 * 1.2  8/14/2019   Release code for FlipIt V1.2 Hardware
 * 1.3  8/16/2019   Adding CHANGE_PRESS for changing game played.
 * 1.4  8/20/2019   Discovered that PWM Open Drain needed to be turned off to limit Sleep Current.
 * 1.5  9/06/2019   Added Reliable button timing 
 * 1.6  9/14/2019   Shorten up Flip sequence.  Start with white and then switch to new color
 * 1.7  9/25/2019   Final power up/down sequence.  
 *                  Set PUBLIC_REV to 1 
 * 1.8 10/3/2019    Brighter LED, Added two part rev blink.
 *                  Set REV to 1.1  
 */

#include "mcc_generated_files/mcc.h"
#include "main.h"

#define FULL_GREEN  24
#define PUBLIC_REV  1
#define PUBLIC_MINOR  1

/*
uint8_t pulse[] = {15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
                     20,245,255,250,210,150,90,55,40,35,32,31,30,30,
                     35,120,125,120,80,40,25,18,15};

uint8_t sine[] = {13,14,16,20,25,31,39,48,57,67,76,86,96,105,114,122,128,133,137,139,140,
                  139,137,133,128,122,114,105,96,86,77,67,57,48,39,31,25,20,16,14,13};
*/

uint8_t sine[] = {22,24,27,34,43,53,66,82,97,114,129,146,163,179,194,207,218,226,233,236,238,
                  236,233,226,218,207,194,179,163,146,131,114,97,82,66,53,43,34,27,24,22};

bool     longPress = false;
bool     shortPress = false;
bool     changePress = false;
uint24_t pressTime = 0;
bool     beaconIsRed = false;
uint8_t  patternIndex = 0;
bool     gameMenuMode = false;
uint8_t  selectedGame = 0;
uint8_t  brightness = 0;
bool     altMode = false;

/*
                         Main application
 */
void main(void)
{
    uint8_t volume;
    
    // initialize the device
    SYSTEM_Initialize();
    
    IOCAF3_SetInterruptHandler(buttonHandler);

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    
    RED_SetHigh();
    RA1_SetHigh();
    BLUE_SetHigh();
    SW_VCC_SetHigh();
    resetVolumeLimit();
    resetTimerMS();
    powerUpTest();
    
    while (1)
    {
        // Update normal beacon if button not pressed.
        if (!buttonPressed(true)){

            // restart sleep timer
            if (shortPress) {
                resetTimerMS();
                clearPresses();
            }

            // Power Down
            if (longPress) {
                resetVolumeLimit();
                clearPresses();
                goToSleep();
                resetTimerMS();
                clearPresses();
            }

            // Battery Saver?
            if (getTimerMS()> BATTERY_SAVER){
                powerDown(true);
            }
                
            // Time to vibrate?
            switch (checkVolume()) {
                case 0:
                default:
                    break;
                    
                case 1:
                    break;
                    
                case 2:
                    tickle();
                    break;
            }
            
            // Update blink display
            // sineLED();
        }
        delay(50);
    }

    // Disable the Global Interrupts
    INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptDisable();
}

void    tickle() 
{
    uint8_t loud = 255;
    
    // Pulse the Motor
    setLED(255, 0, 0);
    delay(40);
    setLED(0, 0, 0);
    delay(80);
    
    for (int blink=0; blink < 3; blink++) {
        setLED(loud, 0, 0);
        delay(20);
        setLED(  0, 0, 0);
        delay(100);
        loud >>= 1;
    }
    delay(1000);
    setLED(  0, 0, 0);
    resetVolumeLimit();
}

/*
void    pulseLED()
{
    setFlag(beaconIsRed, pulse[patternIndex]);
    patternIndex = (patternIndex + 1) % sizeof(pulse);
}
*/

void    delay(uint24_t delayMS)
{
    uint24_t stop = getTimerMS() + delayMS;
    
    while (getTimerMS() < stop) ;
}

void    setLED(uint8_t red, uint8_t green, uint8_t blue )
{
    PWM1_DutyCycleSet(green);
    PWM2_DutyCycleSet(blue);
    PWM3_DutyCycleSet(red);
    
    PWM1_LoadBufferSet();
    PWM2_LoadBufferSet();
    PWM3_LoadBufferSet();
}

void    setVolumeLED(uint8_t vol){
    PWM2_DutyCycleSet(vol);
    PWM2_LoadBufferSet();
}

void buttonHandler(void){
    // ignore a bounce or double press
    if (shortPress || longPress || changePress) 
        return;
    
    if (PRESS_GetValue() == 0) {
        pressTime = getTimerMS();
    }
}

// Indicate the duration the button is down for
bool    buttonPressed( bool poweringDown) {
    // Are we holding the button down right now.
    if (PRESS_GetValue() == 0) {
        stopTriggers();
        if ((getTimerMS() - pressTime) > LONG_PRESS) {
            if (poweringDown) {
                if (brightness > 0)
                    brightness--;
                setLED(0,brightness,0);
            }
            else {
                if (brightness < FULL_GREEN)
                    brightness++;
                setLED(0,brightness,0);
            }
            longPress  = true;
            shortPress = false;
        }
        else {
            //if (poweringDown) 
            brightness = FULL_GREEN ;           
            //else
            //    brightness = 0 ;           
                    
            //setLED(0,brightness,0);
            shortPress = true;
        }
        return true;
    }
    else {
        startTriggers(); 
        return false;
    }
}

void    clearPresses() {
    shortPress  = false;
    longPress   = false;
    changePress = false;
}

void    powerUpTest () {
    delay(200);
    flashRev(0);
    delay(500);
}

/*
 * Do everything required to enter super low power (OFF) mode.
 * We are woken up by another long press
 */
void    powerDown(bool timeout) {
    
    SW_VCC_SetLow();

    // Fade out the Green LED
    if (timeout) {
        for (int b = 32; b >= 0; b-- )
        {
            setLED(0, 0, b);
            delay(50);
        }
    }
    
    while (1) {
        setLED(0,0,0);
        PWM1_Stop();
        PWM2_Stop();
        PWM3_Stop();

        NOP();
        SLEEP();  // Power down the PIC
        NOP();
       
        //Waking up
        PWM1_Start();
        PWM2_Start();
        PWM3_Start();
        
        delay(100);
        clearPresses();
        pressTime = getTimerMS();

        // We have woken up, so wait for button release.
        while (buttonPressed(false)) {
            delay(50);
        };
        setLED(0,0,0);

        // was this a long press
        if (longPress) {
            longPress = false;
            break;
        }
        else {
            shortPress = false;
            brightness = 0;
            while (brightness < FULL_GREEN) {
                brightness++;
                setLED(0,brightness,0);
                delay(30);
            }
            setLED(0,0,0);
            break;
        }
    }

    // Waking up.
    SW_VCC_SetHigh();
    resetVolumeLimit();
    delay(250);
    resetTimerMS();
    clearPresses();
}

void    goToSleep(void) {
    // go offline for specific time.
    // Don't respond to noise or vibration.
    // But wake up with a long press
    stopTriggers();
    SW_VCC_SetLow();

    resetTimerMS();
    while ((getTimerMS() < MUTE_TIMER)) {
        if ((PRESS_GetValue() == 0) && ((getTimerMS() - pressTime) > LONG_PRESS)) 
            break;
        delay(20);
    }
    
    // Waking up.
    SW_VCC_SetHigh();
    for (brightness = 0; brightness < FULL_GREEN; brightness++) {
        setLED(0, 0, brightness);
        delay(50);
    }
    
    // wait for button release
    while(PRESS_GetValue() == 0) {
        delay(5);
    }

    setLED(0, 0, 0);
    startTriggers();
    resetVolumeLimit();
}


void    flashRev(uint8_t greenLevel) {
    
    // Blink the Rev number
    for (int r=0; r < PUBLIC_REV; r++) {
        setLED(0, 64, 0);  // Green
        
        delay(200);
        setLED(0, greenLevel, 0);
        delay(300);
    }

    for (int r=0; r < PUBLIC_MINOR; r++) {
        setLED(0, 0, 64);   // Blue
        
        delay(50);
        setLED(0, greenLevel, 0);
        delay(100);
    }
}

/**
 End of File
*/