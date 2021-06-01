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

#ifndef _CONFIG_H
#define _CONFIG_H

/** D E F I N E S ***************************************************/
#define TRUE 1
#define FALSE 0

/*** ADC Configuration *******************/
/* Uncomment the line below if you want to use the ADC */
// #define ENABLE_ADC TRUE

/* If you are using the ADC specify how many channels you are using
 * for every channel you can read the ADC value from ADC_value[] */
#define ADC_CHANNELS    1


/*** IO expander configuration *********** 
 * BE AWARE: When using the IO expander RC7 and RB1 are used for communication
 * RB0 can only be used as output, in this example we use it as CS */
#define ENABLE_IOEXP TRUE

#define IOEXP_DATA          LATCbits.LATC7
#define IOEXP_CLK           LATBbits.LATB1
#define IOEXP_CS            LATBbits.LATB0


/*** Audio Configuration *****************/
// #define ENABLE_AUDIO TRUE

/* Specify the pin for your audio output, every digital output can be used */
#define AUDIO_OUT           LATBbits.LATB3

#define SERVO_CHANNELS 1

#define SERVO_0_OUT LATBbits.LATB7
// #define SERVO_1_OUT LATBbits.LATB6
// #define SERVO_2_OUT LATBbits.LATB5

/* Define all out- and inputs with readable names */
#define PRG_BUTTON      PORTCbits.RC0
#define LED1_OUT        LATCbits.LATC1
#define LED2_OUT        LATCbits.LATC2

// Rows
#define ROW0            PORTBbits.RB3 // Out Rows
#define ROW1            PORTBbits.RB4 // Out Rows
#define ROW2            PORTBbits.RB5 // Out Rows
#define ROW3            PORTBbits.RB6 // Out Rows
#define ROW4            PORTBbits.RB7 // Out Rows

// Players
#define PLAYER0_BUTTON  PORTCbits.RC2 // In pins
#define PLAYER1_BUTTON  PORTCbits.RC1 // In pins
#define PLAYER2_BUTTON  PORTCbits.RC6 // In pins
#define PLAYER3_BUTTON  PORTAbits.RA0 // In pins
#define PLAYER4_BUTTON  PORTAbits.RA1 // In pins

// Misc
#define BUZZER          PORTBbits.RB2 // Buzzer
#define BUTTON0         PORTAbits.RA6 // Button 0
#define BUTTON1         PORTAbits.RA7 // Button 1

/** I N C L U D E S *************************************************/
#include <xc.h>
#include "func_adc.h"
#include "func_pwm.h"
#include "func_ioexp.h"
#include "func_audio.h"
#include "func_servo.h"

/** G L O B A L   P U B L I C   V A R I A B L E S *******************/
unsigned char timer;
unsigned char state;
extern unsigned char score_select;
extern unsigned char column_select;

extern unsigned char player0_score;
extern unsigned char player1_score;
extern unsigned char player2_score;
extern unsigned char player3_score;
extern unsigned char player4_score;

extern unsigned char dode_mensen_count;

// when a variable is declared 'extern' it also has to be declared in
// the corresponding .c file without the 'extern' keyword
//extern unsigned char led1_output;

// this is an example for implementing a stepper motor
// in your game FSM you can store the direction and amount of steps in a variable
// the IO FSM will read out this variable to set the apropriate outputs
// we use an array here, in case you have multiple stepper motors
//extern unsigned char stepper_steps[1];
//extern unsigned char stepper_direction[1];

// this is an example for implementing a PWM on one of the output pins
// you can configure the PWM output in the fsm_io.c file
//extern unsigned char PWM_duty[1];

/** P U B L I C   P R O T O T Y P E S *******************************/

/** F S M   R O U T I N E S *****************************************/
void fsm_io_init(void);
void fsm_io(void);

void fsm_game_init(void);
void fsm_game(void);

#endif
//EOF----------------------------------------------------------------