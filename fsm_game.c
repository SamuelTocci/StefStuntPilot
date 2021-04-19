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
#define PUSHED 1
#define ROW_ON 1
#define ROW_OFF 0

/** P R I V A T E   V A R I A B L E S *******************************/
static enum {FSM_IDLE,
        STATE1,
        STATE2,
        STATE3,
        STATE4
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
    
    switch (current_state) { 
        case FSM_IDLE :
            ROW4 = ROW_OFF;
            ROW0 = ROW_ON;
            
            if (PLAYER0 == PUSHED)
                current_state = STATE1;
            break;
            
        case STATE1 : 
            ROW0 = ROW_OFF;
            ROW1 = ROW_ON;
            
            if (PLAYER1 == PUSHED)
                current_state = STATE2;
            break;
            
        case STATE2:
            ROW1 = ROW_OFF;
            ROW2 = ROW_ON;
            
            if (PLAYER2 == PUSHED)
                current_state = STATE3;
            break;
            
        case STATE3:
            ROW2 = ROW_OFF;
            ROW3 = ROW_ON;
            
            if (PLAYER3 == PUSHED)
                current_state = STATE4;
            break;
        
        case STATE4:
            ROW3 = ROW_OFF;
            ROW4 = ROW_ON;
            
            if (PLAYER4 == PUSHED)
                current_state = FSM_IDLE;
            break;    
        default:
                current_state = FSM_IDLE;
            break;
    }
}
