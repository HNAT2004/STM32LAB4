/*
 * scheduler.c
 *
 *  Created on: Nov 8, 2024
 *      Author: ADMIN
 */

#include "scheduler.h"

unsigned char Error_code_G = 0;
#define ERROR_SCH_TOO_MANY_TASKS 1
#define ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK 2
#define ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER 3
#define ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START 4
#define ERROR_SCH_LOST_SLAVE 5
#define ERROR_SCH_CAN_BUS_ERROR 6
#define ERROR_I2C_WRITE_BYTE_AT24C64 7
#define ERROR_SCH_CANNOT_DELETE_TASK 8
#define RETURN_ERROR 9
#define RETURN_NORMAL 10
TaskList* list;
uint16_t time_skip;
uint16_t count_task;
void Timer_init(void){

}
void Watchdog_init(void){

}
TaskList* createTaskList() {
    TaskList* list = (TaskList*)malloc(sizeof(TaskList));
    list->head = NULL;
    return list;
}

void SCH_Init(void){
	time_skip = 0;
	count_task = 0;
	Error_code_G = 0;
	Timer_init();
	Watchdog_init();
}

void SCH_Update(void) {
	if(list->head == NULL){
		return;
	}
	time_skip++;
    if(list->head->Delay > 0){
    	if(time_skip < list->head->Delay){
    		list->head->Delay -= time_skip;
    		time_skip = 0;
    	}
    	else{
    		time_skip -= list->head->Delay;
    		list->head->RunMe += 1;
    		list->head->Delay = 0;
    	}
    }
}

sTask* Enqueue(sTask* newTask){
    if (list->head == NULL) {
        list->head = newTask;
        return newTask;
    }
    else {
			sTask* current = list->head;
			sTask* previous = NULL;
			uint32_t delay = newTask->Delay;
			while (current != NULL && current->Delay <= delay) {
				delay -= current->Delay;
				previous = current;
				current = current->next;
		}
		newTask->Delay = delay;
		newTask->next = current;
		if (previous == NULL) {
			list->head = newTask;
		}
		else if(previous -> next != NULL){
		   current->Delay -= delay;
		   previous->next = newTask;
		}
		else{
			previous->next = newTask;
		}
    }
    return newTask;
}
void SCH_Add_Task(void (*pTask)(void), uint32_t delay, uint32_t period) {
	if(count_task > SCH_MAX_TASKS){
		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		return;
	}
	sTask* newTask = malloc(sizeof(sTask));
	newTask->pTask = pTask;
	newTask->Delay = delay + time_skip;
	newTask->Period = period;
	newTask->RunMe = 0;
	newTask->next = NULL;
	Enqueue(newTask);
	count_task++;
}

void SCH_Dispatch_Tasks(void) {
    if (list->head == NULL || list->head->Delay > 0) return;
    list->head->RunMe -= 1;
    sTask* temp = list->head;
    list->head = list->head->next;
    temp->next = NULL;
    temp->Delay = temp->Period;
	temp->pTask();
	if (temp->Period != 0) {
		Enqueue(temp);
	}
	else if(temp->Period > 0 && list->head->RunMe > 0){
		return;
	}
	else if(temp->Period > 0 && list->head->RunMe <= 0){
		free(temp);
		count_task--;
	}
}

uint8_t SCH_Delete_Task(sTask* deleted_task) {
    if (deleted_task == NULL) {
        Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
        return RETURN_ERROR;
    }
    if(deleted_task == list->head){
    	count_task--;
    	list->head = list->head->next;
    	deleted_task->next->Delay += deleted_task->Delay;
    	free(deleted_task);
    }
    sTask* current = list->head;
    sTask* previous = NULL;
    while (current != deleted_task && current != NULL){
        previous = current;
        current = current->next;
    }
	if (current == NULL) {
		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		return RETURN_ERROR;
	}
	if (current->next != NULL) {
		current->next->Delay += current->Delay;
	}
	if(previous != NULL){
		previous->next = current->next;
	}
    Error_code_G = RETURN_NORMAL;
    return Error_code_G ;
}

void SCH_Go_To_Sleep(void){

}
void SCH_Report_Status(void){
#ifdef SCH_REPORT_ERRORS
	if(Error_code_G != Last_error_code_G){
		Error_port = 255 − Error_code_G;
		Last_error_code_G = Error_code_G ;
		if(Error_code_G != 0){
			Error_tick_count_G = 60000;
		}
		else{
			Error_tick_count_G = 0;
		}
	}
	else{
		if(Error_tick_count_G != 0){
			if(−−Error_tick_count_G == 0 ){
				Error_code_G = 0;
			}
		}
	}
#endif
}
