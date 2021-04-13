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
#include <stdlib.h>

/** D E F I N E S ***************************************************/
#define PUSHED 0

/** P R I V A T E   V A R I A B L E S *******************************/
static enum {FSM_IDLE,BLINK_HIGH, BLINK_LOW 
            } current_state;
            
/********************************************************************
 * Function:        void fsm_game_init(void)
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Overview:        This init sets the start state for this FSM and
 *                  may initialize some counters          
 ********************************************************************/
void fsm_game_init(void) {
	current_state = FSM_IDLE;
}

/********************************************************************
 * Function:        void fsm_game(void)
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Overview:        An implementation for a simple reaction game
 ********************************************************************/
void fsm_game(void) {
    int counter = 0;
    int timer = 0;
    switch (current_state) { 
        case FSM_IDLE :
        // *** outputs ***
            //led1_output = 1;
            LED1_OUT = 0;
        // *** transitions ***
            if (PRG_BUTTON == PUSHED)
                counter ++;
                int amount = counter;
                current_state = BLINK_HIGH;
            break;            
        case BLINK_HIGH:
            timer ++;
            if(amount>0 && timer == 100)
                LED1_OUT = 1;
                timer = 0;
                current_state = BLINK_LOW;
            current_state = FSM_IDLE;
            break;
        case BLINK_LOW:
            LED1_OUT = 0;
            timer ++;
            if(timer == 100)
                timer = 0;
                current_state = BLINK_HIGH;
                
        default:
            current_state = FSM_IDLE;
            break;
    }
    
}
