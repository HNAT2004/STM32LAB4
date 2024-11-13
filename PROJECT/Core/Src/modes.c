/*
 * modes.c
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */
#include "modes.h"
#include "fsm_automatic.h"
#include "display7SEG.h"
#include "modify.h"

int time_for_red = 5;
int time_for_yellow = 2;
int time_for_green = 3;

int current_mode = 1;
int save_red = 5;
int save_yellow = 2;
int save_green = 3;

void mode_1(void){
	fsm_automatic_run_X();
	fsm_automatic_run_Y();
	updateBuffer(clock_X, clock_Y);
	countdown();
}

void mode_2(void){
	modifyRedLED();
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
}

void mode_3(void){
	modifyYellowLED();
	if (isButton2Pressed()){
		time_for_yellow++;
		if (time_for_yellow > 99){
			time_for_yellow = 1;
		}
	}
	if (isButton3Pressed()){
		save_yellow = time_for_yellow;
		save_red = save_green + save_yellow;
	}
}

void mode_4(void){
	modifyGreenLED();
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
}

void change_mode(void){
	if (isButton1Pressed()){
		current_mode++;
		if (current_mode > 4){
			current_mode = 1;
		}
		setTimer_X(save_red * 100);
		setTimer_Y(save_green * 100);
		clock_X = save_red;
		clock_Y = save_green;

		time_for_red = save_red;
		time_for_yellow = save_yellow;
		time_for_green = save_green;
	}
}

void run_traffic_light(void){
	switch(current_mode){
	case 1:
		mode_1();
		change_mode();
		break;
	case 2:
		mode_2();
		change_mode();
		break;
	case 3:
		mode_3();
		change_mode();
		break;
	case 4:
		mode_4();
		change_mode();
		break;
	default:
		break;
	}
}
