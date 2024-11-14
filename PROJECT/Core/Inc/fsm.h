/*
 * fsm.h
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "main.h"
#include "button.h"

extern int status;
extern int status_X;
extern int status_Y;
extern int counter_X;
extern int counter_Y;
extern int counter_idle;

#define AUTO_INIT		1
#define AUTO_RED_X		2
#define AUTO_YELLOW_X	3
#define	AUTO_GREEN_X	4

#define AUTO_RED_Y		5
#define AUTO_YELLOW_Y	6
#define	AUTO_GREEN_Y	7

#define MANUAL_RED_X_GREEN_Y	9
#define MANUAL_RED_X_YELLOW_Y	10
#define MANUAL_GREEN_X_RED_Y	11
#define MANUAL_YELLOW_X_RED_Y	12

#define INIT					13
#define AUTO_RED_X_GREEN_Y		14
#define AUTO_RED_X_YELLOW_Y		15
#define AUTO_GREEN_X_RED_Y		16
#define AUTO_YELLOW_X_RED_Y		17

void fsm_automatic_run_X(void);
void fsm_automatic_run_Y(void);
void fsm_automatic_run(void);

void fsm_manual_run(void);

#endif /* INC_FSM_AUTOMATIC_H_ */
