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
#define ON 0
#define OFF 1

/** P R I V A T E   V A R I A B L E S *******************************/

unsigned char player0_score;
unsigned char player1_score;
unsigned char player2_score;
unsigned char player3_score;
unsigned char player4_score;
unsigned char score_select;
unsigned char column_select;
unsigned char dode_mensen_count =0;

enum {R_UPDATE,
        COL_STATE0,
        COL_STATE1,
        COL_STATE2,
        COL_STATE3,
        COL_STATE4
            } column_state;
enum {ROW_STATE0,
        ROW_STATE1,
        ROW_STATE2,
        ROW_STATE3,
        ROW_STATE4,
        EXIT
            } row_state;
/********************************************************************
 * Function:        void fsm_game_init(void)
 * PreCondition:    None
 * Input:           None
 * Output:          None
 * Overview:        This init sets the start state for this FSM and
 *                  may initialize some counters          
 ********************************************************************/
void fsm_game_init(void) {
	column_state = R_UPDATE;
}

void fsm_game(void) {   
    unsigned char flag_outer;
    switch (column_state) { 
        case R_UPDATE : 
            IOEXP_send(0x00, 3);
            switch(row_state) {
                case ROW_STATE0:
                    ROW1 = OFF;
                    ROW2 = OFF;
                    ROW3 = OFF;
                    ROW4 = OFF;
                    ROW0 = ON;
                    
                    flag_outer = 0;
                    score_select = 0;
                    row_state = ROW_STATE1;
                    break;
                    
                case ROW_STATE1:
                    
                    ROW0 = OFF;
                    ROW2 = OFF;
                    ROW3 = OFF;
                    ROW4 = OFF;
                    ROW1 = ON;
                    
                    flag_outer = 0;
                    score_select = 1;
                    row_state = ROW_STATE2;
                    break;
                    
                case ROW_STATE2:
                    
                    ROW0 = OFF;
                    ROW1 = OFF;
                    ROW3 = OFF;
                    ROW4 = OFF;
                    ROW2 = ON;
                    
                    flag_outer = 0;
                    score_select = 2;
                    row_state = ROW_STATE3;
                    break;
                    
                case ROW_STATE3:
                    
                    ROW0 = OFF;
                    ROW1 = OFF;
                    ROW2 = OFF;
                    ROW4 = OFF;
                    ROW3 = ON;
                    
                    flag_outer = 0;
                    score_select = 3;
                    row_state = ROW_STATE4;
                    break;    
                    
                case ROW_STATE4:
                    
                    ROW0 = OFF;
                    ROW1 = OFF;
                    ROW2 = OFF;
                    ROW3 = OFF;
                    ROW4 = ON;
                    
                    flag_outer = 0;
                    score_select = 4;
                    row_state = ROW_STATE0;
                    break;       
                   
                case EXIT:
                    break;
            }
            
        case COL_STATE0 :
            column_select = 0;
            IOEXP_send(0x01, 0);
            
            switch(score_select){
                case 0:
                    if(PLAYER0_BUTTON == OFF && flag_outer == 0 && player0_score >0){
                        player0_score -= 1;
                        flag_outer = 1;
                        if(player0_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 1:
                    if(PLAYER1_BUTTON == ON && flag_outer == 0 && player1_score >0){
                        player1_score -= 1;
                        flag_outer = 1;
                        if(player1_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 2:
                    if(PLAYER2_BUTTON == OFF && flag_outer == 0 && player2_score >0){
                        player2_score -= 1;
                        flag_outer = 1;
                        if(player2_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 3:
                    if(PLAYER3_BUTTON == ON && flag_outer == 0 && player3_score >0){
                        player3_score -= 1;
                        flag_outer = 1;
                        if(player3_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 4:
                    if(PLAYER4_BUTTON == ON && flag_outer == 0 && player4_score >0){
                        player4_score -= 1;
                        flag_outer = 1;
                        if(player4_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                default:
                    break;
            }
            
            column_state = COL_STATE1;
            break;
            
        case COL_STATE1 :
            column_select = 1;
            IOEXP_send(0x02, 0);
            switch(score_select){
                case 0:
                    if(PLAYER0_BUTTON == OFF && flag_outer == 0 && player0_score >0){
                        player0_score -= 1;
                        flag_outer = 1;
                        if(player0_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 1:
                    if(PLAYER1_BUTTON == ON && flag_outer == 0 && player1_score >0){
                        player1_score -= 1;
                        flag_outer = 1;
                        if(player1_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 2:
                    if(PLAYER2_BUTTON == OFF && flag_outer == 0 && player2_score >0){
                        player2_score -= 1;
                        flag_outer = 1;
                        if(player2_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 3:
                    if(PLAYER3_BUTTON == ON && flag_outer == 0 && player3_score >0){
                        player3_score -= 1;
                        flag_outer = 1;
                        if(player3_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 4:
                    if(PLAYER4_BUTTON == ON && flag_outer == 0 && player4_score >0){
                        player4_score -= 1;
                        flag_outer = 1;
                        if(player4_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                default:
                    break;
            }
            
            column_state = COL_STATE2;
            break;
            
        case COL_STATE2:
            column_select = 2;
            IOEXP_send(0x04, 0);
            
            
            column_state = COL_STATE3;
            break;
            
        case COL_STATE3:
            column_select = 3;
            IOEXP_send(0x08, 0);
            
            switch(score_select){
                case 0:
                    if(PLAYER0_BUTTON == ON && flag_outer == 0 && player0_score >0){
                        player0_score -= 1;
                        if(player0_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 1:
                    if(PLAYER1_BUTTON == OFF && flag_outer == 0 && player1_score >0){
                        player1_score -= 1;
                        if(player1_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 2:
                    if(PLAYER2_BUTTON == ON && flag_outer == 0 && player2_score >0){
                        player2_score -= 1;
                        if(player2_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 3:
                    if(PLAYER3_BUTTON == OFF && flag_outer == 0 && player3_score >0){
                        player3_score -= 1;
                        if(player3_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                case 4:
                    if(PLAYER4_BUTTON == OFF && flag_outer == 0 && player4_score >0){
                        player4_score -= 1;
                        if(player4_score == 0){
                            dode_mensen_count +=1;
                        }
                    }
                    break;
                default:
                    break;
            }
        
            column_state = COL_STATE4;
            break;
        
        case COL_STATE4:     
            column_select = 4;
            IOEXP_send(0x00, 0);
            IOEXP_send(0x01, 3);
                        
            column_state = R_UPDATE;
            break;    
        default:
                column_state = R_UPDATE;
            break;
    }
}
