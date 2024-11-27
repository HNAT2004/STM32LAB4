/*
 * scheduler.c
 *
 *  Created on: Nov 8, 2024
 *      Author: ADMIN
 */

#include "scheduler.h"

TaskNode* SCH_Task_List = NULL;
uint32_t Current_Task_ID = 1;
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

void SCH_Init(void){
    TaskNode* current = SCH_Task_List;

    while (current != NULL){
        TaskNode* temp = current;
        current = current->next;
        free(temp);
    }

    SCH_Task_List = NULL;
    Current_Task_ID = 1;
    Timer_init();
    Watchdog_init();
}

uint8_t SCH_Add_Task(void (*pFunction)(), uint32_t Delay, uint32_t Period){
    TaskNode* newTask = (TaskNode*)malloc(sizeof(TaskNode));
    if (newTask == NULL){
        return 0;
    }

    newTask->pTask = pFunction;
    newTask->Delay = Delay;
    newTask->Period = Period;
    newTask->RunMe = 0;
    newTask->TaskID = Current_Task_ID;
    Current_Task_ID++;
    newTask->next = NULL;

    if (SCH_Task_List == NULL || SCH_Task_List->Delay > Delay){
        newTask->next = SCH_Task_List;
        SCH_Task_List = newTask;
    }
    else{
        TaskNode* current = SCH_Task_List;
        while (current->next != NULL && current->next->Delay <= Delay){
            Delay -= current->Delay;
            current = current->next;
        }
        newTask->Delay = Delay;
        newTask->next = current->next;
        current->next = newTask;
    }

    return newTask->TaskID;
}

void SCH_Update(void){
    if (SCH_Task_List != NULL && SCH_Task_List->Delay > 0) {
        SCH_Task_List->Delay--;
    }
}


void SCH_Dispatch_Tasks(void) {
    TaskNode* current = SCH_Task_List;
    while (current != NULL && current->Delay == 0) {
        current->pTask();
        current->RunMe--;

        if (current->Period > 0){
            SCH_Add_Task(current->pTask, current->Period, current->Period);
        }

        TaskNode* temp = current;
        current = current->next;
        free(temp);
    }

    SCH_Task_List = current;
}

uint8_t SCH_Delete_Task(uint32_t TaskID) {
    TaskNode* current = SCH_Task_List;
    TaskNode* previous = NULL;

    while (current != NULL) {
        if (current->TaskID == TaskID) {
            if (previous == NULL) {
                SCH_Task_List = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }

    return 0;
}

void Watchdog_init(void){
	//TODO
}

void Timer_init(void){
	//TODO
}

void SCH_Go_To_Sleep(void){
	//TODO
}

void SCH_Report_Status(void){
#ifdef SCH_REPORT_ERRORS
	if(Error_code_G != Last_error_code_G){
		Error_port = 255 - Error_code_G;
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
			if(--Error_tick_count_G == 0 ){
				Error_code_G = 0;
			}
		}
	}
#endif
}
