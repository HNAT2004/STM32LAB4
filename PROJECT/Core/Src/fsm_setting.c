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
int not_save_flag_red = 0;
int not_save_flag_yellow = 0;
int not_save_flag_green = 0;
int save_value_red = 5;
int save_value_yellow = 2;
int save_value_green = 3;

void modifyRedLED(void){
	HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
	HAL_GPIO_TogglePin(RED_X_GPIO_Port, RED_X_Pin);
	HAL_GPIO_TogglePin(RED_Y_GPIO_Port, RED_Y_Pin);
}

void modifyYellowLED(void){
	HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
	HAL_GPIO_TogglePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin);
	HAL_GPIO_TogglePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin);
}

void modifyGreenLED(void){
	HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
	HAL_GPIO_TogglePin(GREEN_X_GPIO_Port, GREEN_X_Pin);
	HAL_GPIO_TogglePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin);
}

void change_mode(void){
	if (isButton1Pressed()){
		if(current_mode == 2){
			if (not_save_flag_red == 1){
				time_for_red = save_value_red;
			}
		}
		if(current_mode == 3){
			if (not_save_flag_yellow == 1){
				time_for_yellow = save_value_yellow;
			}
		}
		if(current_mode == 4){
			if (not_save_flag_green == 1){
				time_for_green = save_value_green;
			}
		}
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
			if (not_save_flag_red == 0){
				not_save_flag_red = 1;
			}
			time_for_red++;
			if (time_for_red > 99){
				time_for_red = 1;
			}
		}
//		if (isButton1Pressed()){
//			time_for_red = save_value_red;
//		}
		if (isButton3Pressed()){
			not_save_flag_red = 0;
			save_value_red = time_for_red;
			time_for_green = time_for_red - time_for_yellow;
		}
		break;

	case 3:
		if (isButton2Pressed()){
			if (not_save_flag_yellow == 0){
				not_save_flag_yellow = 1;
				save_value_yellow = time_for_yellow;
			}
			time_for_yellow++;
			if (time_for_yellow > 99){
				time_for_yellow = 1;
			}
		}
//		if (isButton1Pressed()){
//			if (not_save_flag_yellow == 1){
//				time_for_yellow = save_value_yellow;
//			}
//			not_save_flag_yellow = 0;
//		}
		if (isButton3Pressed()){
			not_save_flag_yellow = 0;
			save_value_yellow = time_for_yellow;
			time_for_red = time_for_green + time_for_yellow;
		}
		break;

	case 4:
		if (isButton2Pressed()){
			if (not_save_flag_green == 0){
				not_save_flag_green = 1;
				save_value_green = time_for_green;
			}
			time_for_green++;
			if (time_for_green > 99){
				time_for_green = 1;
			}
		}
//		if (isButton1Pressed()){
//			if (not_save_flag_green == 1){
//				time_for_green = save_value_green;
//			}
//			not_save_flag_green = 0;
//		}
		if (isButton3Pressed()){
			not_save_flag_green = 0;
			save_value_green = time_for_green;
			time_for_red = time_for_green + time_for_yellow;
		}
		break;
	}
}
