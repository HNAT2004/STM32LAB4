/*
 * fsm_manual.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
//#include "fsm_manual.h"
//
//void fsm_manual_run(void){
//	switch(status){
//	case MANUAL_RED:
//		//TODO
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
//
//		if (timer_flag_1 == 1){
//			status = AUTO_RED;
//			setTimer_X(500);
//		}
//		if (isButton1Pressed() == 1){
//			status = MANUAL_GREEN;
//			setTimer_X(1000);
//		}
//		break;
//	case MANUAL_YELLOW:
//		//TODO
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
//
//		if (timer_flag_1 == 1){
//			status = AUTO_YELLOW;
//			setTimer_X(200);
//		}
//		if (isButton1Pressed() == 1){
//			status = MANUAL_RED;
//			setTimer_X(1000);
//		}
//		break;
//	case MANUAL_GREEN:
//		//TODO
//		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
//		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
//
//		if (timer_flag_1 == 1){
//			status = AUTO_GREEN;
//			setTimer_X(300);
//		}
//		if (isButton1Pressed() == 1){
//			status = MANUAL_YELLOW;
//			setTimer_X(1000);
//		}
//		break;
//	default:
//		break;
//	}
//}

