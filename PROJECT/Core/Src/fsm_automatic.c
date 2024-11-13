/*
 * fsm_automatic.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
#include "fsm_automatic.h"

void initRed(void){
	HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
}
void initYellow(void){
	HAL_GPIO_TogglePin(YELLOW_GPIO_Port, YELLOW_Pin);
}
void initGreen(void){
	HAL_GPIO_TogglePin(GREEN_GPIO_Port, GREEN_Pin);
}
void brightBlue(void){
	HAL_GPIO_TogglePin(BLUE_GPIO_Port, BLUE_Pin);
}
