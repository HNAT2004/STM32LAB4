/*
 * display7SEG.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
#include "display7SEG.h"

int index_led = 0;
int led_buffer_X[2] = {0, 0};
int led_buffer_Y[2] = {0, 0};

void init7SEG(void){
	HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, SET);
	HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, SET);
	HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, SET);
	HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, SET);
	HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, SET);
	HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, SET);
	HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, SET);
	HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, SET);
	HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, SET);
	HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, SET);
	HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, SET);
	HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, SET);
	HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, SET);
	HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, SET);
}

void display7SEG_X(int number){
	switch(number){
	case 0:
		HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, SET);
		HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, SET);
		HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, SET);
		HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, SET);
		HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, SET);
		HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, SET);
		HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, SET);
		HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, SET);
		HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, SET);
		HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, SET);
		HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, SET);
		HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, SET);
		HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, SET);
		HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, SET);
		HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, SET);
		HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, SET);
		HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, SET);
		HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG0_X_GPIO_Port, SEG0_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_X_GPIO_Port, SEG1_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_X_GPIO_Port, SEG2_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_X_GPIO_Port, SEG3_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_X_GPIO_Port, SEG4_X_Pin, SET);
		HAL_GPIO_WritePin(SEG5_X_GPIO_Port, SEG5_X_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_X_GPIO_Port, SEG6_X_Pin, RESET);
		break;
	default:
		break;
	}
}

void display7SEG_Y(int number){
	switch(number){
	case 0:
		HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG0_Y_GPIO_Port, SEG0_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_Y_GPIO_Port, SEG1_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_Y_GPIO_Port, SEG2_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_Y_GPIO_Port, SEG3_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_Y_GPIO_Port, SEG4_Y_Pin, SET);
		HAL_GPIO_WritePin(SEG5_Y_GPIO_Port, SEG5_Y_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_Y_GPIO_Port, SEG6_Y_Pin, RESET);
		break;
	default:
		break;
	}
}

void update7SEG(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN0_X_GPIO_Port, EN0_X_Pin, RESET);
		HAL_GPIO_WritePin(EN1_X_GPIO_Port, EN1_X_Pin, SET);
		HAL_GPIO_WritePin(EN0_Y_GPIO_Port, EN0_Y_Pin, RESET);
		HAL_GPIO_WritePin(EN1_Y_GPIO_Port, EN1_Y_Pin, SET);
		display7SEG_Y(led_buffer_Y[0]);
		display7SEG_X(led_buffer_X[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_X_GPIO_Port, EN0_X_Pin, SET);
		HAL_GPIO_WritePin(EN1_X_GPIO_Port, EN1_X_Pin, RESET);
		HAL_GPIO_WritePin(EN0_Y_GPIO_Port, EN0_Y_Pin, SET);
		HAL_GPIO_WritePin(EN1_Y_GPIO_Port, EN1_Y_Pin, RESET);
		display7SEG_Y(led_buffer_Y[1]);
		display7SEG_X(led_buffer_X[1]);
		break;
	default:
		break;
	}
}

void updateBufferOption(void){
	if (current_mode == 1){
		updateBufferClock();
	}
	else if (current_mode != 1){
		updateBufferMode();
	}
}

void updateBufferClock(void){
	if (clock_X < 10){
		led_buffer_X[0] = 0;
		led_buffer_X[1] = clock_X;
	}
	if (clock_X >= 10){
		led_buffer_X[0] = clock_X / 10;
		led_buffer_X[1] = clock_X % 10;
	}
	if (clock_Y < 10){
		led_buffer_Y[0] = 0;
		led_buffer_Y[1] = clock_Y;
	}
	if (clock_Y >= 10){
		led_buffer_Y[0] = clock_Y / 10;
		led_buffer_Y[1] = clock_Y % 10;
	}
	update7SEG(index_led++);
	if (index_led > 1){
		index_led = 0;
	}
}

void updateBufferMode(void){
	led_buffer_X[0] = 0;
	led_buffer_X[1] = current_mode;
	if (current_mode == 2){
		if (time_for_red < 10){
			led_buffer_Y[0] = 0;
			led_buffer_Y[1] = time_for_red;
		}
		if (time_for_red >= 10){
			led_buffer_Y[0] = time_for_red / 10;
			led_buffer_Y[1] = time_for_red % 10;
		}
	}
	if (current_mode == 3){
		if (time_for_yellow < 10){
			led_buffer_Y[0] = 0;
			led_buffer_Y[1] = time_for_yellow;
		}
		if (time_for_yellow >= 10){
			led_buffer_Y[0] = time_for_yellow / 10;
			led_buffer_Y[1] = time_for_yellow % 10;
		}
	}
	if (current_mode == 4){
		if (time_for_green < 10){
			led_buffer_Y[0] = 0;
			led_buffer_Y[1] = time_for_green;
		}
		if (save_red >= 10){
			led_buffer_Y[0] = time_for_green / 10;
			led_buffer_Y[1] = time_for_green % 10;
		}
	}
	update7SEG(index_led++);
	if (index_led > 1){
		index_led = 0;
	}
}


