/*
 * software_timer.h
 *
 *  Created on: Oct 20, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag_0;
extern int timer_flag_1;
extern int timer_flag_2;
extern int timer_flag_3;
extern int timer_flag_4;
extern int timer_flag_5;

void setTimer(int duration);
void setTimer_X(int duration);
void setTimer_Y(int duration);
void setTimer_Clock(int duration);
void setTimer_Sweeper_X(int duration);
void setTimer_Sweeper_Y(int duration);
void timer_run(void);
//void isTimerExpired(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
