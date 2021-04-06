#ifdef C
/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "can.h"
#include "dac.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "uartBSP.h"
#include "Led.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC3_Init();
  MX_CAN1_Init();
  MX_CAN2_Init();
  MX_DAC_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_I2C3_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_USART6_UART_Init();
  MX_TIM5_Init();
  MX_TIM10_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 15;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
#endif


#include "mcal_reg.h"

/*
		RED LED PI5
		GPIOI = AHB1
		GPIOI = 0x4002 1C00
		MODEREG OFFSET = 0x00
		
typedef struct{
    __IO    uint32_t    MODER;          // GPIO port mode register
    __IO    uint32_t    OTYPER;
    __IO    uint32_t    OSPEEDR;    
    __IO    uint32_t    PUPDR;
    __IO    uint32_t    IDR;
    __IO    uint32_t    ODR;
    __IO    uint32_t    BSRR;
    __IO    uint32_t    LCKR;
    __IO    uint32_t    AFL[2]; 
}GPIO_TypeDef;


typedef struct{
    __IO    uint32_t    CR;             // RCC clock control register
    __IO    uint32_t    PLLCFGR;        // RCC PLL configuration register
    __IO    uint32_t    CFGR;           // RCC clock configuration register
    __IO    uint32_t    CIR;            // RCC clock interrupt register
    __IO    uint32_t    AHB1RSTR;       // RCC AHB1 peripheral reset register
    __IO    uint32_t    AHB2RSTR;       // RCC AHB2 peripheral reset register
    __IO    uint32_t    AHB3RSTR;       // RCC AHB3 peripheral reset register
    __IO    uint32_t    DUMMY1;         // Dummy 32 bits
    __IO    uint32_t    APB1RSTR;       // RCC APB1 peripheral reset register
    __IO    uint32_t    APB2RSTR;       // RCC APB2 peripheral reset register
    __IO    uint32_t    DUMMY2;         // Dummy 32 bits
    __IO    uint32_t    DUMMY3;         // Dummy 32 bits
    __IO    uint32_t    AHB1ENR;        // RCC AHB1 peripheral clock enable register
    __IO    uint32_t    AHB2ENR;        // RCC AHB2 peripheral clock enable register
    __IO    uint32_t    AHB3ENR;        // RCC AHB3 peripheral clock enable register
    __IO    uint32_t    DUMMY4;         // Dummy 32 bits
    __IO    uint32_t    APB1ENR;        // RCC APB1 peripheral clock enable register
    __IO    uint32_t    APB2ENR;        // RCC APB2 peripheral clock enable register
    __IO    uint32_t    DUMMY5;         // Dummy 32 bits
    __IO    uint32_t    DUMMY6;         // Dummy 32 bits
    __IO    uint32_t    AHB1LPENR;      // RCC AHB1 peripheral clock enable in low power mode register     
    __IO    uint32_t    AHB2LPENR;      // RCC AHB2 peripheral clock enable in low power mode register
    __IO    uint32_t    AHB3LPENR;      // RCC AHB3 peripheral clock enable in low power mode register
    __IO    uint32_t    DUMMY7;         // Dummy 32 bits
    __IO    uint32_t    APB1LPENR;      // RCC APB1 peripheral clock enable in low power mode register
    __IO    uint32_t    APB2LPENR;      // RCC APB2 peripheral clock enable in low power mode register
    __IO    uint32_t    DUMMY8;         // Dummy 32 bits
    __IO    uint32_t    DUMMY9;         // Dummy 32 bits
    __IO    uint32_t    BDCR;           // RCC Backup domain control register (
    __IO    uint32_t    CSR;            // RCC clock control & status register
    __IO    uint32_t    DUMMY10;        // Dummy 32 bits
    __IO    uint32_t    DUMMY11;        // Dummy 32 bits
    __IO    uint32_t    SSCGR;          // RCC spread spectrum clock generation register
    __IO    uint32_t    PLLI2SCFGR;     // RCC PLLI2S configuration register
    __IO    uint32_t    PLLSAICFGR;     // RCC PLL configuration register
    __IO    uint32_t    DCKCFGR;        // RCC Dedicated Clock Configuration Register 
}RCC_TypeDef;


	AHB1ENR = AHB1 + RCC + 0x30 = 0x4002 3800 + 0x30 = 0x40023830

*/

#define				RCC_AHB1ENR				(*((volatile unsigned int *)0x40023830))
#define				GPIOI_MODER				(*((volatile unsigned int *)0x40021C00))				
#define				GPIOI_ODR				(*((volatile unsigned int *)0x40021C14))				


class Led
{
	public:
		typedef std::uint32_t 	port_type;
		typedef std::uint32_t	bval_type;
		
	Led(const port_type p, bval_type b):port(p),bval(b)
	{
		
		/*Disable pin*/
		//*((volatile uint32_t*)GPIOB) = bval;		// C
		*reinterpret_cast<volatile port_type *>(port) 
			&= ~(1U<<bval);
		
		/*Set pin mode to output*/
		const port_type gpio_mode_register = port - 0x14;
		*reinterpret_cast<volatile port_type *>(gpio_mode_register)
			|= (1U<<(bval*2));
		
	}
	
	void toggle()const{
		*reinterpret_cast<volatile port_type *>(port)
			^= (1U<<bval);
	}
	
	void pseudodelayMs(int n){
		for(;n>0;n++){
			for(int i=0;i<3200;i++){
			}
		}
	}
	
	private:
		const port_type port;
		const bval_type bval;
};



int main(void){
	RCC_AHB1ENR |= (1U<<8);	// Enable clocl GPIOI
	Led led7(mcal::reg::gpioi, mcal::reg::goio_pin_7);

	while(1){
		led7.toggle();
		led7.pseudodelayMs(500);
	}
}
