/*
 * display7SEG.h
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "global.h"
#include "software_timer.h"

void display7SEG_X(int number);
void display7SEG_Y(int number);
void display7SEG(int number);
void update7SEG_X(int index);
void update7SEG_Y(int index);
void update7SEG(int index);
void updateBuffer_X(int second_X);
void updateBuffer_Y(int second_Y);
void updateBuffer(int second_X, int second_Y);

#endif /* INC_DISPLAY7SEG_H_ */
