/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC12LF1572
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RED aliases
#define RED_TRIS                 TRISAbits.TRISA0
#define RED_LAT                  LATAbits.LATA0
#define RED_PORT                 PORTAbits.RA0
#define RED_WPU                  WPUAbits.WPUA0
#define RED_OD                   ODCONAbits.ODA0
#define RED_ANS                  ANSELAbits.ANSA0
#define RED_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RED_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RED_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RED_GetValue()           PORTAbits.RA0
#define RED_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RED_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RED_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define RED_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define RED_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define RED_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define RED_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define RED_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set BLUE aliases
#define BLUE_TRIS                 TRISAbits.TRISA2
#define BLUE_LAT                  LATAbits.LATA2
#define BLUE_PORT                 PORTAbits.RA2
#define BLUE_WPU                  WPUAbits.WPUA2
#define BLUE_OD                   ODCONAbits.ODA2
#define BLUE_ANS                  ANSELAbits.ANSA2
#define BLUE_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define BLUE_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define BLUE_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define BLUE_GetValue()           PORTAbits.RA2
#define BLUE_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define BLUE_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define BLUE_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define BLUE_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define BLUE_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define BLUE_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define BLUE_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define BLUE_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set PRESS aliases
#define PRESS_TRIS                 TRISAbits.TRISA3
#define PRESS_PORT                 PORTAbits.RA3
#define PRESS_WPU                  WPUAbits.WPUA3
#define PRESS_GetValue()           PORTAbits.RA3
#define PRESS_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define PRESS_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define PRESS_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define PRESS_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)

// get/set MIC aliases
#define MIC_TRIS                 TRISAbits.TRISA4
#define MIC_LAT                  LATAbits.LATA4
#define MIC_PORT                 PORTAbits.RA4
#define MIC_WPU                  WPUAbits.WPUA4
#define MIC_OD                   ODCONAbits.ODA4
#define MIC_ANS                  ANSELAbits.ANSA4
#define MIC_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define MIC_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define MIC_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define MIC_GetValue()           PORTAbits.RA4
#define MIC_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define MIC_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define MIC_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define MIC_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define MIC_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define MIC_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define MIC_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define MIC_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SW_VCC aliases
#define SW_VCC_TRIS                 TRISAbits.TRISA5
#define SW_VCC_LAT                  LATAbits.LATA5
#define SW_VCC_PORT                 PORTAbits.RA5
#define SW_VCC_WPU                  WPUAbits.WPUA5
#define SW_VCC_OD                   ODCONAbits.ODA5
#define SW_VCC_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SW_VCC_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SW_VCC_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SW_VCC_GetValue()           PORTAbits.RA5
#define SW_VCC_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SW_VCC_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SW_VCC_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SW_VCC_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SW_VCC_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define SW_VCC_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF3 pin functionality
 * @Example
    IOCAF3_ISR();
 */
void IOCAF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF3_SetInterruptHandler() method.
    This handler is called every time the IOCAF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(IOCAF3_InterruptHandler);

*/
extern void (*IOCAF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF3_SetInterruptHandler() method.
    This handler is called every time the IOCAF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF3_SetInterruptHandler(IOCAF3_DefaultInterruptHandler);

*/
void IOCAF3_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/