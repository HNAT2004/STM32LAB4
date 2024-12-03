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

TaskNode* SCH_Task_List = NULL;
uint32_t Current_Task_ID = 1;

void SCH_Init(void){
    SCH_Task_List = NULL;
    Current_Task_ID = 1;
}

uint8_t SCH_Add_Task(void (*pFunction)(void), uint32_t Delay, uint32_t Period){	//Thêm trước khi vào while(1)
    if (!pFunction){
        return RETURN_ERROR;
    }

    TaskNode* newNode = (TaskNode*)malloc(sizeof(TaskNode));

    newNode->task.pTask = pFunction;
    newNode->task.Delay = Delay;
    newNode->task.Period = Period;
    newNode->task.RunMe = 0;
    newNode->task.TaskID = Current_Task_ID++;
    newNode->next = NULL;

    if (!SCH_Task_List || SCH_Task_List->task.Delay > Delay){
        if (SCH_Task_List){
            SCH_Task_List->task.Delay -= Delay;
        }
        newNode->next = SCH_Task_List;
        SCH_Task_List = newNode;		//Trường hợp node mới được thêm vào đầu danh sách
    }
    else{
        TaskNode* current = SCH_Task_List;
        while (current->next && current->next->task.Delay <= Delay){	//Kiểm tra vị trí sẽ đặt node mới, nếu Delay node mới < Delay Task tiếp theo thì đặt vào
            Delay -= current->next->task.Delay;
            current = current->next;
        }
        if (current->next){
            current->next->task.Delay -= Delay;
        }
        newNode->task.Delay = Delay;
        newNode->next = current->next;
        current->next = newNode;
    }

    return newNode->task.TaskID;
}

void SCH_Update(void){		//Thêm trong timer_interrupt
    if (SCH_Task_List && SCH_Task_List->task.Delay > 0){
        SCH_Task_List->task.Delay--;
    }
}

void SCH_Dispatch_Tasks(void){			//Thực hiện trong while(1)
    while (SCH_Task_List && SCH_Task_List->task.Delay == 0){
        TaskNode* current = SCH_Task_List;

        current->task.pTask();

        if (current->task.Period > 0){
            current->task.Delay = current->task.Period;		// Reset thời gian chờ
            SCH_Task_List = current->next;					// Loại bỏ task khỏi đầu danh sách
            SCH_Add_Task(current->task.pTask, current->task.Delay, current->task.Period);	//Thêm lại task vào danh sách
            free(current);
        }
        else{
            SCH_Task_List = current->next;				//One-shot task => Xóa task
            free(current);
        }
    }
}

uint8_t SCH_Delete_Task(uint32_t TaskID){
    if (!SCH_Task_List){
        return RETURN_ERROR;
    }

    TaskNode* current = SCH_Task_List;
    TaskNode* previous = NULL;

    while (current) {
        if (current->task.TaskID == TaskID){			//Kiểm tra task hiện tại có TaskID trùng với ID cần xóa
            if (!previous){								//Nếu previous là NULL => current đang trỏ đến node đầu tiên trong danh sách.
                SCH_Task_List = current->next;
            }
            else{
                if (current->next){
                    current->next->task.Delay += current->task.Delay;	//Nếu có task đứng sau, cộng Delay của task bị xóa vào Delay của task tiếp theo.
                }
                previous->next = current->next;
            }
            free(current);							//Free bộ nhớ
            return RETURN_NORMAL;
        }
        previous = current;
        current = current->next;
    }

    return RETURN_ERROR;
}


void Timer_init(void){
	//TODO
}

void Watchdog_init(void){
	//TODO
}

void SCH_Go_To_Sleep(void){
	//TODO
}

void SCH_Report_Status(void) {
#ifdef SCH_REPORT_ERRORS
    if (Error_code_G != Last_error_code_G) {
        Error_port = 255 - Error_code_G;
        Last_error_code_G = Error_code_G;
        if (Error_code_G != 0) {
            Error_tick_count_G = 60000;
        } else {
            Error_tick_count_G = 0;
        }
    } else {
        if (Error_tick_count_G != 0) {
            if (--Error_tick_count_G == 0) {
                Error_code_G = 0;
            }
        }
    }
#endif
}
