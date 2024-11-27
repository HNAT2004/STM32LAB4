/*
 * tasks.c
 *
 *  Created on: Nov 27, 2024
 *      Author: ADMIN
 */
#include "tasks.h"

void Task1(void){
	HAL_GPIO_TogglePin(BLUE_1_GPIO_Port, BLUE_1_Pin);
}
void Task2(void){
	HAL_GPIO_TogglePin(BLUE_2_GPIO_Port, BLUE_2_Pin);
}
void Task3(void){
	HAL_GPIO_TogglePin(BLUE_3_GPIO_Port, BLUE_3_Pin);
}
void Task4(void){
	HAL_GPIO_TogglePin(BLUE_4_GPIO_Port, BLUE_4_Pin);
}
void Task5(void){
	HAL_GPIO_TogglePin(BLUE_5_GPIO_Port, BLUE_5_Pin);
}
