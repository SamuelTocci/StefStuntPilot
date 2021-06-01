/*********************************************************************
 *
 *                  EE 4 Project - Code Template
 *
 *********************************************************************
 * Processor:       PIC18F25K50
 * Compiler:        XC8 1.35+
 * Author:          Jeroen Van Aken
 * Updated:         03/03/2020
 ********************************************************************/

/** I N C L U D E S *************************************************/
#include "config.h"

/** D E F I N E S ***************************************************/

/** P U B L I C   V A R I A B L E S *********************************/
// in order for the variable to be used in other file, it also has to
// be declared as 'extern' in the config.h file
unsigned char led1_output;
unsigned char counter;

unsigned char player0_score;
unsigned char player1_score;
unsigned char player2_score;
unsigned char player3_score;
unsigned char player4_score;

unsigned char dode_mensen_count;

/** P R I V A T E   V A R I A B L E S *******************************/

/** P R I V A T E   P R O T O T Y P E S *****************************/
static void init(void);
static void OpenTimer0(unsigned char intEnable);
static unsigned char timed_to_1ms(void);

/********************************************************************/
/** P U B L I C   D E C L A R A T I O N S ***************************/
/********************************************************************
 * Function:        void main(void)
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Overview:        Main program entry point
 ********************************************************************/
void main(void) {
	init();						//initialize the system
    OpenTimer0(1);
    IOEXP_init();
    player0_score = 3;
    player1_score = 3;
    player2_score = 3;
    player3_score = 3;
    player4_score = 3;
    counter = 0;
	while(timed_to_1ms()) {
        counter++;
        if(dode_mensen_count == 4){
            if(counter %16 == 0){
                IOEXP_send(0x02, 3); //GP1
            }
            if(counter %32 == 1){
                IOEXP_send(0x04, 3); //GP2
            }
            if(counter %64 == 2){
                IOEXP_send(0x08, 3); //GP3
            }
            break;
        }
        if(column_select != 4 && dode_mensen_count != 4){
            switch(score_select){
                case 0:
                    if(counter %3 == 0 && player0_score > 0){
                        IOEXP_send(0x02, 3); //GP1
                    }
                    if(counter %3 == 1 && player0_score > 1){
                        IOEXP_send(0x04, 3); //GP2
                    }
                    if(counter %3 == 2 && player0_score > 2){
                        IOEXP_send(0x08, 3); //GP3
                    }
                    break;
                case 1:
                    if(counter %3 == 0 && player1_score > 0){
                        IOEXP_send(0x02, 3); //GP1
                    }
                    if(counter %3 == 1 && player1_score > 1){
                        IOEXP_send(0x04, 3); //GP2
                    }
                    if(counter %3 == 2 && player1_score > 2){
                        IOEXP_send(0x08, 3); //GP3
                    }
                    break;
                case 2:
                    if(counter %3 == 0 && player2_score > 0){
                        IOEXP_send(0x02, 3); //GP1
                    }
                    if(counter %3 == 1 && player2_score > 1){
                        IOEXP_send(0x04, 3); //GP2
                    }
                    if(counter %3 == 2 && player2_score > 2){
                        IOEXP_send(0x08, 3); //GP3
                    }
                    break;
                case 3:
                    if(counter %3 == 0 && player3_score > 0){
                        IOEXP_send(0x02, 3); //GP1
                    }
                    if(counter %3 == 1 && player3_score > 1){
                        IOEXP_send(0x04, 3); //GP2
                    }
                    if(counter %3 == 2 && player3_score > 2){
                        IOEXP_send(0x08, 3); //GP3
                    }
                    break;
                case 4:
                    if(counter %3 == 0 && player4_score > 0){
                        IOEXP_send(0x02, 3); //GP1
                    }
                    if(counter %3 == 1 && player4_score > 1){
                        IOEXP_send(0x04, 3); //GP2
                    }
                    if(counter %3 == 2 && player4_score > 2){
                        IOEXP_send(0x08, 3); //GP3
                    }
                    break;
            }
        }
        if(column_select == 4 && dode_mensen_count != 4){
            switch(score_select){
                case 0:
                    if(counter %4 == 0 && player0_score > 0){
                        IOEXP_send(0x02, 3); //GP1
                    }
                    if(counter %4 == 1 && player0_score > 1){
                        IOEXP_send(0x04, 3); //GP2
                    }
                    if(counter %4 == 2 && player0_score > 2){
                        IOEXP_send(0x08, 3); //GP3
                    }
                    if(counter %4 == 3){
                        IOEXP_send(0x01, 3);
                    }
                    break;
                case 1:
                    if(counter %4 == 0 && player1_score > 0){
                        IOEXP_send(0x02, 3); //GP1
                    }
                    if(counter %4 == 1 && player1_score > 1){
                        IOEXP_send(0x04, 3); //GP2
                    }
                    if(counter %4 == 2 && player1_score > 2){
                        IOEXP_send(0x08, 3); //GP3
                    }
                    if(counter %4 == 3){
                        IOEXP_send(0x01, 3);
                    }
                    break;
                case 2:
                    if(counter %4 == 0 && player2_score > 0){
                        IOEXP_send(0x02, 3); //GP1
                    }
                    if(counter %4 == 1 && player2_score > 1){
                        IOEXP_send(0x04, 3); //GP2
                    }
                    if(counter %4 == 2 && player2_score > 2){
                        IOEXP_send(0x08, 3); //GP3
                    }
                    if(counter %4 == 3){
                        IOEXP_send(0x01, 3);
                    }
                    break;
                case 3:
                    if(counter %4 == 0 && player3_score > 0){
                        IOEXP_send(0x02, 3); //GP1
                    }
                    if(counter %4 == 1 && player3_score > 1){
                        IOEXP_send(0x04, 3); //GP2
                    }
                    if(counter %4 == 2 && player3_score > 2){
                        IOEXP_send(0x08, 3); //GP3
                    }
                    if(counter %4 == 3){
                        IOEXP_send(0x01, 3);
                    }
                    break;
                case 4:
                    if(counter %4 == 0 && player4_score > 0){
                        IOEXP_send(0x02, 3); //GP1
                    }
                    if(counter %4 == 1 && player4_score > 1){
                        IOEXP_send(0x04, 3); //GP2
                    }
                    if(counter %4 == 2 && player4_score > 2){
                        IOEXP_send(0x08, 3); //GP3
                    }
                    if(counter %4 == 3){
                        IOEXP_send(0x01, 3);
                    }
                    break;
            }
        }
        
        if (counter == 250)
        {
            if(dode_mensen_count != 4){
                fsm_game();
            }
            counter = 0;
        }
	}
}

/********************************************************************/
/** P R I V A T E   D E C L A R A T I O N S *************************/
/********************************************************************
 * Function:        void init(void)
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Overview:        Init is a centralize initialization routine.              
 *                  It will initialze all IO and variables, also the
 *                  hardware_init() for the hardware functions should
 *                  be called here.              
 ********************************************************************/
static void init(void) {
    LATA = 0x00;                // Reset all IO
    LATB = 0x00;
    LATC = 0x00;
    OpenTimer0(FALSE);          // start timer for 1ms loop
    OSCCONbits.IRCF = 0b111;    // put internal clock in 7th gear
    
	// Configure I/O as input (1) or output (0)
    TRISAbits.TRISA0 = 1;       // ADC IN
    ANSELAbits.ANSA0 = 0;       // 1 = Analog
    TRISAbits.TRISA1 = 1;       // Player 4 IN
    ANSELAbits.ANSA1 = 0;       // 0 = digital IO
    TRISAbits.TRISA2 = 0;       // Slave select 0 OUT
    ANSELAbits.ANSA2 = 0;       // 0 = digital IO
    TRISAbits.TRISA3 = 0;       // Slave select 1 OUT
    ANSELAbits.ANSA3 = 0;       // 0 = digital IO
    TRISAbits.TRISA4 = 0;       // Backup pin
    TRISAbits.TRISA5 = 0;       // Backup pin
    ANSELAbits.ANSA5 = 0;       // Backup pin
    TRISAbits.TRISA6 = 1;       // Gamemode Toggle IN
    TRISAbits.TRISA7 = 1;       // Gamemode Toggle IN 
    
    TRISBbits.TRISB0 = 0;       // IO expander data out SDO OUT
    ANSELBbits.ANSB0 = 0;       // 0 = digital IO
    TRISBbits.TRISB1 = 0;       // IO expander clock CLK
    ANSELBbits.ANSB1 = 0;       // 0 = digital IO
    TRISBbits.TRISB2 = 0;       // Buzzer OUT
    ANSELBbits.ANSB2 = 0;       // 0 = digital IO
    TRISBbits.TRISB3 = 0;       // Row 1 OUT
    ANSELBbits.ANSB3 = 0;       // 0 = digital IO
    TRISBbits.TRISB4 = 0;       // Row 2 OUT
    ANSELBbits.ANSB4 = 0;       // 0 = digital IO
    TRISBbits.TRISB5 = 0;       // Row 3 OUT
    ANSELBbits.ANSB5 = 0;       // 0 = digital IO
    TRISBbits.TRISB6 = 0;       // Row 4 OUT
    TRISBbits.TRISB7 = 0;       // Row 5 OUT
    
    TRISCbits.TRISC0 = 1;       // Pushbutton on the µC PCB
    TRISCbits.TRISC1 = 1;       // Player 1 IN
    TRISCbits.TRISC2 = 0;       // Player 0 IN
    ANSELCbits.ANSC2 = 0;       // 0 = digital IO
    TRISCbits.TRISC6 = 0;       // Player 2 IN
    ANSELCbits.ANSC6 = 0;       // 0 = digital IO
    TRISCbits.TRISC7 = 0;       // SDO OUT
    ANSELCbits.ANSC7 = 0;       // 0 = digital IO
    
    led1_output = 0;
    //PWM_duty[0] = 0;

    fsm_io_init();
    fsm_game_init();
       
#if ENABLE_SERVO == TRUE
    SERVO_init();
#endif
#if ENABLE_ADC == TRUE
    ADC_init();
#endif
#if ENABLE_IOEXP == TRUE
    IOEXP_init();
#endif
#if ENABLE_AUDIO == TRUE
    AUDIO_init();
#endif  
}

/********************************************************************
 * Function:        void OpenTimer0(unsigned char intEnable)
 * PreCondition:    None
 * Input:           intEnable: enable Timer0 interrupt
 * Output:          None
 * Overview:        Will initialize Timer0 given the parameters
 ********************************************************************/
static void OpenTimer0(unsigned char intEnable) {
    T0CONbits.T08BIT = 1;
    T0CONbits.T0CS = 0;
    T0CONbits.PSA = 0;
    T0CONbits.T0PS = 0b011;
    TMR0H = 0;                // Reset Timer0 to 0x0000
    TMR0L = 7;
    
    INTCONbits.TMR0IE = intEnable & 0x01u;
    INTCONbits.GIE = (intEnable & 0x01u) | INTCONbits.GIE;
    INTCON2bits.TMR0IP = 0;
    INTCONbits.TMR0IF = 0;      // Clear Timer0 overflow flag
}

/********************************************************************
 * Function:        void timed_to_1ms(void)
 * PreCondition:    OpenTimer0(FALSE)
 * Input:           None
 * Output:          None
 * Overview:        Stays in a while loop, doing NOP until Timer0 
 *                  generates an overflow
 ********************************************************************/
static unsigned char timed_to_1ms(void) {
	while(!INTCONbits.TMR0IF){Nop();};
    TMR0L = 7;     // tuned to 1ms
	INTCONbits.TMR0IF = 0;
    return 1;
}

/********************************************************************
 * Function:        void interrupt_high_handler(void)
 * PreCondition:    GIEH need to be set
 * Input:           None
 * Output:          None
 * Overview:        This routine is called whenever a high interrupt 
 *                  condition is  reached
 ********************************************************************/	
void __interrupt(high_priority) interrupt_high_handler(void) {
    if(INTCONbits.TMR0IF == 1)
    {
        TMR0L = 0x00;                   //reload the value to the Timer0
        INTCONbits.TMR0IF=0;            //CLEAR interrupt flag when you are done!!!
    }
    
#if ENABLE_AUDIO == TRUE
    AUDIO_ISR();
#endif
}

/********************************************************************
 * Function:        void interrupt_low_handler(void)
 * PreCondition:    GIEL need to be set
 * Input:           None
 * Output:          None
 * Overview:        This routine is called whenever a low interrupt 
 *                  condition is  reached
 ********************************************************************/	
void __interrupt(low_priority) interrupt_low_handler(void) {
#if ENABLE_ADC == TRUE
    ADC_ISR();
#endif
#if ENABLE_SERVO == TRUE
    SERVO_ISR();
#endif
}
//EOF-------------------------------------------------------------------------
