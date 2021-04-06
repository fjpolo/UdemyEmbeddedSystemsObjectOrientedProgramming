/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4xx_ll_i2c.h"
#include "stm32f4xx_ll_spi.h"
#include "stm32f4xx_ll_usart.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_dma.h"

#include "stm32f4xx_ll_exti.h"

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
#define A19_Pin GPIO_PIN_3
#define A19_GPIO_Port GPIOE
#define HOLD_SRAM_Pin GPIO_PIN_2
#define HOLD_SRAM_GPIO_Port GPIOE
#define SRAM_UB_Pin GPIO_PIN_1
#define SRAM_UB_GPIO_Port GPIOE
#define SRAM_LB_Pin GPIO_PIN_0
#define SRAM_LB_GPIO_Port GPIOE
#define BNO_INT_Pin GPIO_PIN_13
#define BNO_INT_GPIO_Port GPIOG
#define User_Button_Pin GPIO_PIN_7
#define User_Button_GPIO_Port GPIOD
#define A20_Pin GPIO_PIN_4
#define A20_GPIO_Port GPIOE
#define A21_Pin GPIO_PIN_5
#define A21_GPIO_Port GPIOE
#define CS_SRAM_Pin GPIO_PIN_6
#define CS_SRAM_GPIO_Port GPIOE
#define LED_GREEN_Pin GPIO_PIN_7
#define LED_GREEN_GPIO_Port GPIOB
#define GPO_A2_Pin GPIO_PIN_6
#define GPO_A2_GPIO_Port GPIOB
#define CAN2_TERM_Pin GPIO_PIN_15
#define CAN2_TERM_GPIO_Port GPIOG
#define CAN1_TERM_Pin GPIO_PIN_12
#define CAN1_TERM_GPIO_Port GPIOG
#define LED_YELLOW_Pin GPIO_PIN_11
#define LED_YELLOW_GPIO_Port GPIOG
#define SRAM_CE_Pin GPIO_PIN_10
#define SRAM_CE_GPIO_Port GPIOG
#define SRAM_WAIT_Pin GPIO_PIN_6
#define SRAM_WAIT_GPIO_Port GPIOD
#define D2_Pin GPIO_PIN_0
#define D2_GPIO_Port GPIOD
#define LED_RED_Pin GPIO_PIN_7
#define LED_RED_GPIO_Port GPIOI
#define O_6_Pin GPIO_PIN_5
#define O_6_GPIO_Port GPIOI
#define SRAM_WE_Pin GPIO_PIN_5
#define SRAM_WE_GPIO_Port GPIOD
#define D3_Pin GPIO_PIN_1
#define D3_GPIO_Port GPIOD
#define GPO_WE1_Pin GPIO_PIN_3
#define GPO_WE1_GPIO_Port GPIOI
#define GPO_D_Pin GPIO_PIN_2
#define GPO_D_GPIO_Port GPIOI
#define O_5_Pin GPIO_PIN_4
#define O_5_GPIO_Port GPIOI
#define GPO_OE_Pin GPIO_PIN_4
#define GPO_OE_GPIO_Port GPIOD
#define GPO_A1_Pin GPIO_PIN_3
#define GPO_A1_GPIO_Port GPIOD
#define BUS_1_ORANGE_Pin GPIO_PIN_2
#define BUS_1_ORANGE_GPIO_Port GPIOD
#define BUS_2_ORANGE_Pin GPIO_PIN_15
#define BUS_2_ORANGE_GPIO_Port GPIOH
#define A0_Pin GPIO_PIN_0
#define A0_GPIO_Port GPIOF
#define O_7_Pin GPIO_PIN_10
#define O_7_GPIO_Port GPIOI
#define O_8_Pin GPIO_PIN_11
#define O_8_GPIO_Port GPIOI
#define BUS_2_GREEN_Pin GPIO_PIN_9
#define BUS_2_GREEN_GPIO_Port GPIOC
#define O_2_Pin GPIO_PIN_3
#define O_2_GPIO_Port GPIOH
#define BUS_1_GREEN_Pin GPIO_PIN_8
#define BUS_1_GREEN_GPIO_Port GPIOC
#define A2_Pin GPIO_PIN_2
#define A2_GPIO_Port GPIOF
#define A1_Pin GPIO_PIN_1
#define A1_GPIO_Port GPIOF
#define EMB_fest_Pin GPIO_PIN_6
#define EMB_fest_GPIO_Port GPIOC
#define A3_Pin GPIO_PIN_3
#define A3_GPIO_Port GPIOF
#define A4_Pin GPIO_PIN_4
#define A4_GPIO_Port GPIOF
#define O_4_Pin GPIO_PIN_5
#define O_4_GPIO_Port GPIOH
#define A5_Pin GPIO_PIN_5
#define A5_GPIO_Port GPIOF
#define A15_Pin GPIO_PIN_5
#define A15_GPIO_Port GPIOG
#define A14_Pin GPIO_PIN_4
#define A14_GPIO_Port GPIOG
#define A13_Pin GPIO_PIN_3
#define A13_GPIO_Port GPIOG
#define HEX_4_Pin GPIO_PIN_10
#define HEX_4_GPIO_Port GPIOF
#define HEX_2_Pin GPIO_PIN_9
#define HEX_2_GPIO_Port GPIOF
#define HEX_1_Pin GPIO_PIN_8
#define HEX_1_GPIO_Port GPIOF
#define TP7_Pin GPIO_PIN_11
#define TP7_GPIO_Port GPIOH
#define TP5_Pin GPIO_PIN_10
#define TP5_GPIO_Port GPIOH
#define D1_Pin GPIO_PIN_15
#define D1_GPIO_Port GPIOD
#define A12_Pin GPIO_PIN_2
#define A12_GPIO_Port GPIOG
#define A11_Pin GPIO_PIN_1
#define A11_GPIO_Port GPIOG
#define CS_FLASH_Pin GPIO_PIN_6
#define CS_FLASH_GPIO_Port GPIOH
#define TP6_Pin GPIO_PIN_9
#define TP6_GPIO_Port GPIOH
#define D0_Pin GPIO_PIN_14
#define D0_GPIO_Port GPIOD
#define A18_Pin GPIO_PIN_13
#define A18_GPIO_Port GPIOD
#define A7_Pin GPIO_PIN_13
#define A7_GPIO_Port GPIOF
#define A10_Pin GPIO_PIN_0
#define A10_GPIO_Port GPIOG
#define D10_Pin GPIO_PIN_13
#define D10_GPIO_Port GPIOE
#define A17_Pin GPIO_PIN_12
#define A17_GPIO_Port GPIOD
#define A16_Pin GPIO_PIN_11
#define A16_GPIO_Port GPIOD
#define D15_Pin GPIO_PIN_10
#define D15_GPIO_Port GPIOD
#define A6_Pin GPIO_PIN_12
#define A6_GPIO_Port GPIOF
#define A9_Pin GPIO_PIN_15
#define A9_GPIO_Port GPIOF
#define D5_Pin GPIO_PIN_8
#define D5_GPIO_Port GPIOE
#define D6_Pin GPIO_PIN_9
#define D6_GPIO_Port GPIOE
#define D8_Pin GPIO_PIN_11
#define D8_GPIO_Port GPIOE
#define D11_Pin GPIO_PIN_14
#define D11_GPIO_Port GPIOE
#define GPO_WE2_Pin GPIO_PIN_12
#define GPO_WE2_GPIO_Port GPIOB
#define D14_Pin GPIO_PIN_9
#define D14_GPIO_Port GPIOD
#define D13_Pin GPIO_PIN_8
#define D13_GPIO_Port GPIOD
#define HEX_8_Pin GPIO_PIN_11
#define HEX_8_GPIO_Port GPIOF
#define A8_Pin GPIO_PIN_14
#define A8_GPIO_Port GPIOF
#define D4_Pin GPIO_PIN_7
#define D4_GPIO_Port GPIOE
#define D7_Pin GPIO_PIN_10
#define D7_GPIO_Port GPIOE
#define D9_Pin GPIO_PIN_12
#define D9_GPIO_Port GPIOE
#define D12_Pin GPIO_PIN_15
#define D12_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
