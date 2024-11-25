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
#include "global.h"
#include "fsm_setting.h"

extern int counter_X;
extern int counter_Y;
extern int counter_idle;
extern int clock_X;
extern int clock_Y;

void fsm_automatic_run(void);
void fsm_manual_run(void);
void countdown(void);

#endif /* INC_FSM_AUTOMATIC_H_ */
