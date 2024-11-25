/*
 * fsm_setting.h
 *
 *  Created on: Nov 19, 2024
 *      Author: ADMIN
 */

#ifndef INC_FSM_SETTING_H_
#define INC_FSM_SETTING_H_

#include "main.h"
#include "global.h"
#include "button.h"
#include "display7SEG.h"
#include "fsm.h"

extern int current_mode;
extern int time_for_red;
extern int time_for_yellow;
extern int time_for_green;
extern int not_save_flag;

void modifyRedLED(void);
void modifyYellowLED(void);
void modifyGreenLED(void);
void mode_1(void);
void mode_2(void);
void mode_3(void);
void mode_4(void);
void change_mode(void);
void change_clock_value(void);
void check_save(void);

#endif /* INC_FSM_SETTING_H_ */
