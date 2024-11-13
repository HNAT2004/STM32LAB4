/*
 * fsm.h
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "main.h"

extern int status_X;
extern int status_Y;
extern int counter_X;
extern int counter_Y;

#define INIT			1
#define AUTO_RED_X		2
#define AUTO_YELLOW_X	3
#define	AUTO_GREEN_X	4

#define AUTO_RED_Y		5
#define AUTO_YELLOW_Y	6
#define	AUTO_GREEN_Y	7

#define MANUAL_RED_X	8
#define MANUAL_YELLOW_X	9
#define MANUAL_GREEN_X	10

#define MANUAL_RED_Y	11
#define MANUAL_YELLOW_Y	12
#define MANUAL_GREEN_Y	13

void fsm_automatic_run_X(void);
void fsm_automatic_run_Y(void);

void fsm_manual_run_X(void);
void fsm_manual_run_Y(void);

#endif /* INC_FSM_AUTOMATIC_H_ */
