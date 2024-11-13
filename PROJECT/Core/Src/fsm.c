/*
 * fsm.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
#include <fsm.h>

int counter_X = 0;
int counter_Y = 0;
int status_X = INIT;
int status_Y = INIT;

void fsm_automatic_run_X(void){
	switch(status_X){
	case INIT:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		status_X = AUTO_RED_X;
		counter_X = 500;
		break;

	case AUTO_RED_X:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		counter_X--;
		if (counter_X <= 0){
			status_X = AUTO_GREEN_X;
			counter_X = 300;
		}
		break;

	case AUTO_YELLOW_X:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_SET);
		counter_X--;
		if (counter_X <= 0){
			status_X = AUTO_RED_X;
			counter_X = 500;
		}
		break;

	case AUTO_GREEN_X:
		HAL_GPIO_WritePin(RED_X_GPIO_Port, RED_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_X_GPIO_Port, YELLOW_X_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_X_GPIO_Port, GREEN_X_Pin, GPIO_PIN_RESET);
		counter_X--;
		if (counter_X <= 0){
			status_X = AUTO_YELLOW_X;
			counter_X = 200;
		}
		break;

	default:
		break;
	}
}

void fsm_automatic_run_Y(void){
	switch(status_Y){
	case INIT:
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);

		status_Y = AUTO_GREEN_Y;
		counter_Y = 300;
		break;

	case AUTO_RED_Y:
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		counter_Y--;
		if (counter_Y <= 0){
			status_Y = AUTO_GREEN_Y;
			counter_Y = 300;
		}
		break;

	case AUTO_YELLOW_Y:
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_SET);
		counter_Y--;
		if (counter_Y <= 0){
			status_Y = AUTO_RED_Y;
			counter_Y = 500;
		}
		break;

	case AUTO_GREEN_Y:
		HAL_GPIO_WritePin(RED_Y_GPIO_Port, RED_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(YELLOW_Y_GPIO_Port, YELLOW_Y_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GREEN_Y_GPIO_Port, GREEN_Y_Pin, GPIO_PIN_RESET);
		counter_Y--;
		if (counter_Y <= 0){
			status_Y = AUTO_YELLOW_Y;
			counter_Y = 200;
		}
		break;

	default:
		break;
	}
}
