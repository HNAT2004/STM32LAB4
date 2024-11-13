/*
 * global.h
 *
 *  Created on: Oct 21, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT			1
#define AUTO_RED_X		2
#define AUTO_YELLOW_X 	3
#define AUTO_GREEN_X	4
#define AUTO_RED_Y		5
#define AUTO_YELLOW_Y 	6
#define AUTO_GREEN_Y	7

#define MANUAL_RED		12
#define MANUAL_YELLOW	13
#define MANUAL_GREEN	14

extern int status_X;
extern int status_Y;
extern int current_mode;
#endif /* INC_GLOBAL_H_ */
