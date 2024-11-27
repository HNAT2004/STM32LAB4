/*
 * scheduler.h
 *
 *  Created on: Nov 8, 2024
 *      Author: ADMIN
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct {
    void (*pTask)(void);
    uint32_t Delay;
    uint32_t Period;
    uint8_t RunMe;
    uint32_t TaskID;
}sTask;

typedef struct TaskNode {
    sTask task;
    struct TaskNode* head;
    struct TaskNode* next;
}TaskNode;

extern TaskNode* SCH_Task_List;

void SCH_Init(void);

uint8_t SCH_Add_Task(void (*pFunction)(), uint32_t Delay, uint32_t Period);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

uint8_t SCH_Delete_Task(uint32_t TaskID);

void Watchdog_init(void);

void Timer_init(void);

void SCH_Go_To_Sleep(void);

void SCH_Report_Status(void);

#endif /* INC_SCHEDULER_H_ */
