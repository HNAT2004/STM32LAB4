/*
 * button.c
 *
 *  Created on: Oct 20, 2024
 *      Author: ADMIN
 */
#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int KeyReg0_B1 = NORMAL_STATE;	//button 1
int KeyReg1_B1 = NORMAL_STATE;
int KeyReg2_B1 = NORMAL_STATE;
int KeyReg3_B1 = NORMAL_STATE;

int KeyReg0_B2 = NORMAL_STATE;	//button 2
int KeyReg1_B2 = NORMAL_STATE;
int KeyReg2_B2 = NORMAL_STATE;
int KeyReg3_B2 = NORMAL_STATE;

int KeyReg0_B3 = NORMAL_STATE;	//button 3
int KeyReg1_B3 = NORMAL_STATE;
int KeyReg2_B3 = NORMAL_STATE;
int KeyReg3_B3 = NORMAL_STATE;


int timerForKeyPress_1 = 200;
int timerForKeyPress_2 = 200;
int timerForKeyPress_3 = 200;

void subKeyProcess_1(void){
	button1_flag = 1;
}

void subKeyProcess_2(void){
	button2_flag = 1;
}

void subKeyProcess_3(void){
	button3_flag = 1;
}

int isButton1Pressed(void){
	if (button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	else return 0;
}

int isButton2Pressed(void){
	if (button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	else return 0;
}

int isButton3Pressed(void){
	if (button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	else return 0;
}

void getKeyInput_1(void){
	KeyReg0_B1 = KeyReg1_B1;
	KeyReg1_B1 = KeyReg2_B1;
	KeyReg2_B1 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin); //Read current signal of button
	if ((KeyReg0_B1 == KeyReg1_B1) && (KeyReg1_B1 == KeyReg2_B1)){	//Debounce
		if (KeyReg3_B1 != KeyReg2_B1){
			KeyReg3_B1 = KeyReg2_B1;
			if (KeyReg2_B1 == PRESSED_STATE){
				subKeyProcess_1();
				timerForKeyPress_1 = 200;
			}
		}
		else{
			timerForKeyPress_1--;
			if (timerForKeyPress_1 == 0){
				KeyReg3_B1 = NORMAL_STATE;
			}
		}
	}
}

void getKeyInput_2(void){
	KeyReg0_B2 = KeyReg1_B2;
	KeyReg1_B2 = KeyReg2_B2;
	KeyReg2_B2 = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin); //Read current signal of button
	if ((KeyReg0_B2 == KeyReg1_B2) && (KeyReg1_B2 == KeyReg2_B2)){	//Debounce
		if (KeyReg3_B2 != KeyReg2_B2){
			KeyReg3_B2 = KeyReg2_B2;
			if (KeyReg2_B2 == PRESSED_STATE){
				subKeyProcess_2();
				timerForKeyPress_2 = 200;
			}
		}
		else{
			timerForKeyPress_2--;
			if (timerForKeyPress_2 == 0){
				KeyReg3_B2 = NORMAL_STATE;
			}
		}
	}
}

void getKeyInput_3(void){
	KeyReg0_B3 = KeyReg1_B3;
	KeyReg1_B3 = KeyReg2_B3;
	KeyReg2_B3 = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin); //Read current signal of button
	if ((KeyReg0_B3 == KeyReg1_B3) && (KeyReg1_B3 == KeyReg2_B3)){	//Debounce
		if (KeyReg3_B3 != KeyReg2_B3){
			KeyReg3_B3 = KeyReg2_B3;
			if (KeyReg2_B3 == PRESSED_STATE){
				subKeyProcess_3();
				timerForKeyPress_3 = 200;
			}
		}
		else{
			timerForKeyPress_3--;
			if (timerForKeyPress_3 == 0){
				KeyReg3_B3 = NORMAL_STATE;
			}
		}
	}
}
