/*
 * button.h
 *
 *  Created on: Nov 13, 2024
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET

extern int button1_flag;
extern int button2_flag;

void getKeyInput_1(void);
void getKeyInput_2(void);

int isButton1Pressed(void);
int isButton2Pressed(void);

void subKeyProcess_1(void);
void subKeyProcess_2(void);

#endif /* INC_BUTTON_H_ */
