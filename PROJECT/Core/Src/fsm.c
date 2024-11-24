/*
 * fsm.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
#include <fsm.h>

int counter_X = 0;
int counter_Y = 0;
int counter_idle = 1000;
int clock_X = 0;
int clock_Y = 0;
int save_red = 5;
int save_yellow = 2;
int save_green = 3;

void countdown(void){
	clock_X--;
	clock_Y--;
}

void fsm_automatic_run(void){
	switch(status){
	case INIT:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		status = AUTO_RED_X_GREEN_Y;
		clock_X = save_red;
		clock_Y = save_green;
		counter_X = save_red * 50;
		counter_Y = save_green * 50;
		break;

	case AUTO_RED_X_GREEN_Y:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_RESET);
		counter_X--;
		counter_Y--;
		if (counter_Y <= 0){
			status = AUTO_RED_X_YELLOW_Y;
			counter_Y = 200 / 2;
			clock_Y = save_yellow;
		}
		break;

	case AUTO_RED_X_YELLOW_Y:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		counter_X--;
		counter_Y--;
		if (counter_X <= 0 && counter_Y <= 0){
			status = AUTO_GREEN_X_RED_Y;
			counter_X = 300 / 2;
			counter_Y = 500 / 2;
			clock_X = save_green;
			clock_Y = save_red;
		}
		break;

	case AUTO_GREEN_X_RED_Y:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		counter_X--;
		counter_Y--;
		if (counter_X <= 0){
			status = AUTO_YELLOW_X_RED_Y;
			counter_X = 200 / 2;
			clock_X = save_yellow;
		}
		break;
	case AUTO_YELLOW_X_RED_Y:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		counter_X--;
		counter_Y--;
		if (counter_X <= 0 && counter_Y <= 0){
			status = AUTO_RED_X_GREEN_Y;
			counter_X = 500 / 2;
			counter_Y = 300 / 2;
			clock_X = save_red;
			clock_Y = save_green;
		}
		break;

	default:
		break;
	}
}

void fsm_manual_run(void){
	switch(status){
	case MANUAL_RED_X_GREEN_Y:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_RESET);
		counter_idle--;
		if (counter_idle <= 0){
			counter_idle = 1000;
			status = AUTO_RED_X_GREEN_Y;
		}
		if (isButton3Pressed()){
			status = MANUAL_RED_X_YELLOW_Y;
			counter_idle = 1000;
		}
		break;
	case MANUAL_RED_X_YELLOW_Y:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		counter_idle--;
		if (counter_idle <= 0){
			counter_idle = 1000;
			status = AUTO_RED_X_YELLOW_Y;
		}
		if (isButton2Pressed()){
			status = AUTO_RED_X_YELLOW_Y;
			counter_idle = 1000;
			break;
		}
		if (isButton3Pressed()){
			status = MANUAL_GREEN_X_RED_Y;
			counter_idle = 1000;
		}
		break;
	case MANUAL_GREEN_X_RED_Y:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		counter_idle--;
		if (counter_idle <= 0){
			counter_idle = 1000;
			status = AUTO_GREEN_X_RED_Y;
		}
		if (isButton2Pressed()){
			status = AUTO_GREEN_X_RED_Y;
			counter_idle = 1000;
			break;
		}
		if (isButton3Pressed()){
			status = MANUAL_YELLOW_X_RED_Y;
			counter_idle = 1000;
		}
		break;
	case MANUAL_YELLOW_X_RED_Y:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		counter_idle--;
		if (counter_idle <= 0){
			counter_idle = 1000;
			status = AUTO_YELLOW_X_RED_Y;
		}
		if (isButton2Pressed()){
			status = AUTO_YELLOW_X_RED_Y;
			counter_idle = 1000;
			break;
		}
		if (isButton3Pressed()){
			status = MANUAL_RED_X_GREEN_Y;
			counter_idle = 1000;
		}
		break;
	default:
		break;
	}
}
