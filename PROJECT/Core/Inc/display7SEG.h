/*
 * display7SEG.h
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "main.h"
#include "fsm.h"
#include "fsm_setting.h"

void display7SEG_X(int number);
void display7SEG_Y(int number);
void update7SEG(int index);
void updateBufferClock(void);
void updateBufferMode(void);
void updateBufferOption(void);
void init7SEG(void);

#endif /* INC_DISPLAY7SEG_H_ */
