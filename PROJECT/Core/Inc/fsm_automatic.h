/*
 * fsm_automatic.h
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"
#include "display7SEG.h"
#include "software_timer.h"
#include "modes.h"

extern int clock_X;
extern int clock_Y;

void fsm_automatic_run_X(void);
void fsm_automatic_run_Y(void);
void countdown(void);

#endif /* INC_FSM_AUTOMATIC_H_ */
