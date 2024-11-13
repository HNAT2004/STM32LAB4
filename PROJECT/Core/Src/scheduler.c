/*
 * scheduler.c
 *
 *  Created on: Nov 8, 2024
 *      Author: ADMIN
 */

#include "scheduler.h"

#define TICK	10

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;


void SCH_Init(void){
	unsigned char i;
	for (int i = 0; i < SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}

}

void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	if (current_index_task < SCH_MAX_TASKS){
		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY/TICK;
		SCH_tasks_G[current_index_task].Period = PERIOD/TICK;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}
}

void SCH_Update(void){
	for (int index = 0; i < SCH_MAX_TASKS; index++){
		if (SCH_tasks_G[index].Delay > 0){
			SCH_tasks_G[index].Delay--;
		}
		else{
			SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
			SCH_tasks_G[index].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	for (int i = 0; i < current_index_task; i++){
		if (SCH_tasks_G[i].RunMe > 0){
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
		}
	}
}

void SCH_Delete_Task(uint TASK_INDEX){

}

void Watchdog_init(void){

}

void Timer_init(void){

}
