/*
 * fsm_setting.c
 *
 *  Created on: Nov 19, 2024
 *      Author: ADMIN
 */

#include "fsm_setting.h"

int time_for_red = 5;
int time_for_yellow = 2;
int time_for_green = 3;
int current_mode = 1;

void modifyRedLED(void){
	if (current_mode == 2){
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_TogglePin(RED_X_GPIO_Port, RED_X_Pin);
		HAL_GPIO_TogglePin(RED_Y_GPIO_Port, RED_Y_Pin);
	}
}

void modifyYellowLED(void){
	if (current_mode == 3){
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_TogglePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin);
		HAL_GPIO_TogglePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin);
	}
}

void modifyGreenLED(void){
	if (current_mode == 4){
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_TogglePin(GREEN_X_GPIO_Port, GREEN_X_Pin);
		HAL_GPIO_TogglePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin);
	}
}

void change_mode(void){
	if (isButton1Pressed()){
		current_mode++;
		if (current_mode > 4){
			current_mode = 1;
		}
	}
}

void mode_1(void){
	if (current_mode == 1){
		fsm_automatic_run();
	}
}

void mode_2(void){
	if (current_mode == 2){
		modifyRedLED();
	}
}

void mode_3(void){
	if (current_mode == 3){
		modifyYellowLED();
	}
}

void mode_4(void){
	if (current_mode == 4){
		modifyGreenLED();
	}
}

void change_clock_value(void){
	switch(current_mode){
	case 2:
		if (isButton2Pressed()){
			time_for_red++;
			if (time_for_red > 99){
				time_for_red = 1;
			}
		}
		if (isButton3Pressed()){
			save_red = time_for_red;
			save_green = save_red - save_yellow;
		}
		else{
			time_for_red = save_red;
		}
	case 3:
		if (isButton2Pressed()){
			time_for_yellow++;
			if (time_for_yellow > 99){
				time_for_yellow = 1;
			}
		}
		if (isButton3Pressed()){
			save_yellow = time_for_yellow;
			save_red = save_green + save_yellow;
		}else{
			time_for_yellow = save_yellow;
		}
	case 4:
		if (isButton2Pressed()){
			time_for_green++;
			if (time_for_green > 99){
				time_for_green = 1;
			}
		}
		if (isButton3Pressed()){
			save_green = time_for_green;
			save_red = save_green + save_yellow;
		}
		else{
			time_for_green = save_green;
		}
	}
}
