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
		clock_X = time_for_red;
		clock_Y = time_for_green;
		counter_X = time_for_red * 50;
		counter_Y = time_for_green * 50;
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
			counter_Y = time_for_yellow * 50;
			clock_Y = time_for_yellow;
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
			counter_X = time_for_green * 50;
			counter_Y = time_for_red * 50;
			clock_X = time_for_green;
			clock_Y = time_for_red;
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
			counter_X = time_for_yellow * 50;
			clock_X = time_for_yellow;
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
			counter_X = time_for_red * 50;
			counter_Y = time_for_green * 50;
			clock_X = time_for_red;
			clock_Y = time_for_green;
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
