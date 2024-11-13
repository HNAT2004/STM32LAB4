/*
 * button.h
 *
 *  Created on: Oct 20, 2024
 *      Author: ADMIN
 */
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

void getKeyInput_1(void);
void getKeyInput_2(void);
void getKeyInput_3(void);

int isButton1Pressed(void);
int isButton2Pressed(void);
int isButton3Pressed(void);

void subKeyProcess_1(void);
void subKeyProcess_2(void);
void subKeyProcess_3(void);

#endif /* INC_BUTTON_H_ */
