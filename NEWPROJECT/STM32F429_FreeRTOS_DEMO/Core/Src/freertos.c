/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for Task1_LED */
osThreadId_t Task1_LEDHandle;
const osThreadAttr_t Task1_LED_attributes = {
  .name = "Task1_LED",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Task2_USART1 */
osThreadId_t Task2_USART1Handle;
const osThreadAttr_t Task2_USART1_attributes = {
  .name = "Task2_USART1",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
extern UART_HandleTypeDef huart1;
/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Func1_LED(void *argument);
void Func2_USART1(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of Task1_LED */
  Task1_LEDHandle = osThreadNew(Func1_LED, NULL, &Task1_LED_attributes);

  /* creation of Task2_USART1 */
  Task2_USART1Handle = osThreadNew(Func2_USART1, NULL, &Task2_USART1_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Func1_LED */
/**
  * @brief  Function implementing the Task1_LED thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Func1_LED */
void Func1_LED(void *argument)
{
  /* USER CODE BEGIN Func1_LED */
  /* Infinite loop */
  for(;;)
  {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	osDelay(100);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
	osDelay(100);
  }
  /* USER CODE END Func1_LED */
}

/* USER CODE BEGIN Header_Func2_USART1 */
/**
* @brief Function implementing the Task2_USART1 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Func2_USART1 */
void Func2_USART1(void *argument)
{
  /* USER CODE BEGIN Func2_USART1 */
	uint8_t TxData[20]= "usart1 transmit!\n";
  /* Infinite loop */
  for(;;)
  {
	  HAL_UART_Transmit(&huart1,TxData,20,0xffff);
    osDelay(500);
  }
  /* USER CODE END Func2_USART1 */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
