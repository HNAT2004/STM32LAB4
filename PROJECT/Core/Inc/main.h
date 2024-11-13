/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED_X_Pin GPIO_PIN_1
#define RED_X_GPIO_Port GPIOA
#define YELLOW_X_Pin GPIO_PIN_2
#define YELLOW_X_GPIO_Port GPIOA
#define GREEN_X_Pin GPIO_PIN_3
#define GREEN_X_GPIO_Port GPIOA
#define RED_Y_Pin GPIO_PIN_4
#define RED_Y_GPIO_Port GPIOA
#define YELLOW_Y_Pin GPIO_PIN_5
#define YELLOW_Y_GPIO_Port GPIOA
#define GREEN_Y_Pin GPIO_PIN_6
#define GREEN_Y_GPIO_Port GPIOA
#define SEG0_X_Pin GPIO_PIN_7
#define SEG0_X_GPIO_Port GPIOA
#define SEG0_Y_Pin GPIO_PIN_0
#define SEG0_Y_GPIO_Port GPIOB
#define SEG1_Y_Pin GPIO_PIN_1
#define SEG1_Y_GPIO_Port GPIOB
#define SEG2_Y_Pin GPIO_PIN_2
#define SEG2_Y_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_10
#define BUTTON_2_GPIO_Port GPIOB
#define BUTTON_3_Pin GPIO_PIN_11
#define BUTTON_3_GPIO_Port GPIOB
#define EN1_Y_Pin GPIO_PIN_12
#define EN1_Y_GPIO_Port GPIOB
#define SEG1_X_Pin GPIO_PIN_8
#define SEG1_X_GPIO_Port GPIOA
#define SEG2_X_Pin GPIO_PIN_9
#define SEG2_X_GPIO_Port GPIOA
#define SEG3_X_Pin GPIO_PIN_10
#define SEG3_X_GPIO_Port GPIOA
#define SEG4_X_Pin GPIO_PIN_11
#define SEG4_X_GPIO_Port GPIOA
#define SEG5_X_Pin GPIO_PIN_12
#define SEG5_X_GPIO_Port GPIOA
#define SEG6_X_Pin GPIO_PIN_13
#define SEG6_X_GPIO_Port GPIOA
#define EN0_X_Pin GPIO_PIN_14
#define EN0_X_GPIO_Port GPIOA
#define EN1_X_Pin GPIO_PIN_15
#define EN1_X_GPIO_Port GPIOA
#define SEG3_Y_Pin GPIO_PIN_3
#define SEG3_Y_GPIO_Port GPIOB
#define SEG4_Y_Pin GPIO_PIN_4
#define SEG4_Y_GPIO_Port GPIOB
#define SEG5_Y_Pin GPIO_PIN_5
#define SEG5_Y_GPIO_Port GPIOB
#define SEG6_Y_Pin GPIO_PIN_6
#define SEG6_Y_GPIO_Port GPIOB
#define EN0_Y_Pin GPIO_PIN_7
#define EN0_Y_GPIO_Port GPIOB
#define BUTTON_1_Pin GPIO_PIN_9
#define BUTTON_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
