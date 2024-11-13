/*
 * display7SEG.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
#include "display7SEG.h"

int index_led_X = 0;
int index_led_Y = 0;
int index_led = 0;
int led_buffer_X[2] = {0, 0};
int led_buffer_Y[2] = {0, 0};

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

void update7SEG_Y(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN0_Y_GPIO_Port, EN0_Y_Pin, RESET);
		HAL_GPIO_WritePin(EN1_Y_GPIO_Port, EN1_Y_Pin, SET);
		display7SEG_Y(led_buffer_Y[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_Y_GPIO_Port, EN0_Y_Pin, SET);
		HAL_GPIO_WritePin(EN1_Y_GPIO_Port, EN1_Y_Pin, RESET);
		display7SEG_Y(led_buffer_Y[1]);
		break;
	default:
		break;
	}
}

void update7SEG_X(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN0_X_GPIO_Port, EN0_X_Pin, RESET);
		HAL_GPIO_WritePin(EN1_X_GPIO_Port, EN1_X_Pin, SET);
		display7SEG_X(led_buffer_X[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_X_GPIO_Port, EN0_X_Pin, SET);
		HAL_GPIO_WritePin(EN1_X_GPIO_Port, EN1_X_Pin, RESET);
		display7SEG_X(led_buffer_X[1]);
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

void updateBuffer_X(int second_X){
	if (second_X < 10){
		led_buffer_X[0] = 0;
		led_buffer_X[1] = second_X;
	}
	if (second_X >= 10){
		led_buffer_X[0] = second_X / 10;
		led_buffer_X[1] = second_X % 10;
	}
	if(timer_flag_0 == 1){					//7SEG sweeper
		update7SEG_X(index_led_X++);
		if (index_led_X > 1){
			index_led_X = 0;
		}
		setTimer_Sweeper_X(25);
	}
}

void updateBuffer_Y(int second_Y){
	if (second_Y < 10){
		led_buffer_Y[0] = 0;
		led_buffer_Y[1] = second_Y;
	}
	if (second_Y >= 10){
		led_buffer_Y[0] = second_Y / 10;
		led_buffer_Y[1] = second_Y % 10;
	}
	if(timer_flag_4 == 1){					//7SEG sweeper
		update7SEG_Y(index_led_Y++);
		if (index_led_Y > 1){
			index_led_Y = 0;
		}
		setTimer_Sweeper_Y(25);
	}
}

void updateBuffer(int second_X, int second_Y){
	if (second_X < 10){
		led_buffer_X[0] = 0;
		led_buffer_X[1] = second_X;
	}
	if (second_X >= 10){
		led_buffer_X[0] = second_X / 10;
		led_buffer_X[1] = second_X % 10;
	}
	if (second_Y < 10){
		led_buffer_Y[0] = 0;
		led_buffer_Y[1] = second_Y;
	}
	if (second_Y >= 10){
		led_buffer_Y[0] = second_Y / 10;
		led_buffer_Y[1] = second_Y % 10;
	}
	if(timer_flag_0 == 1){					//7SEG sweeper
		update7SEG(index_led++);
		if (index_led > 1){
			index_led = 0;
		}
		setTimer_Sweeper_X(25);
	}
}
