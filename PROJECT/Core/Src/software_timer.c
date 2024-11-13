/*
 * software_timer.c
 *
 *  Created on: Oct 20, 2024
 *      Author: ADMIN
 */
#include "software_timer.h"
int timer_flag_0 = 0;
int timer_flag_1 = 0;
int timer_flag_2 = 0;
int timer_flag_3 = 0;
int timer_flag_4 = 0;
int timer_flag_5 = 0;

int timer_counter_0 = 0;
int timer_counter_1 = 0;
int timer_counter_2 = 0;
int timer_counter_3 = 0;
int timer_counter_4 = 0;
int timer_counter_5 = 0;

void setTimer_Sweeper_X(int duration){
	timer_counter_0 = duration;
	timer_flag_0 = 0;
}

void setTimer_X(int duration){
	timer_counter_1 = duration;
	timer_flag_1 = 0;				//Start count-down
}

void setTimer_Y(int duration){
	timer_counter_2 = duration;
	timer_flag_2 = 0;				//Start count-down
}

void setTimer_Clock(int duration){
	timer_counter_3 = duration;
	timer_flag_3 = 0;				//Start count-down
}

void setTimer_Sweeper_Y(int duration){
	timer_counter_4 = duration;
	timer_flag_4 = 0;				//Start count-down
}

void setTimer(int duration){
	timer_counter_5 = duration;
	timer_flag_5 = 0;
}

void timer_run(void){
	if(timer_counter_0 > 0){
		timer_counter_0--;
		if(timer_counter_0 <= 0){
			timer_flag_0 = 1;		//Time's up
		}
	}
	if(timer_counter_1 > 0){
		timer_counter_1--;
		if(timer_counter_1 <= 0){
			timer_flag_1 = 1;		//Time's up
		}
	}
	if(timer_counter_2 > 0){
		timer_counter_2--;
		if(timer_counter_2 <= 0){
			timer_flag_2 = 1;		//Time's up
		}
	}
	if(timer_counter_3 > 0){
		timer_counter_3--;
		if(timer_counter_3 <= 0){
			timer_flag_3 = 1;		//Time's up
		}
	}
	if(timer_counter_4 > 0){
		timer_counter_4--;
		if(timer_counter_4 <= 0){
			timer_flag_4 = 1;		//Time's up
		}
	}
	if(timer_counter_5 > 0){
		timer_counter_5--;
		if(timer_counter_5 <= 0){
			timer_flag_5 = 1;		//Time's up
		}
	}
}

