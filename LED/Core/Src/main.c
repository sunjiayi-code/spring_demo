/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include<stdio.h>
#include<string.h>
#define RED_LED_GPIO GPIOB
#define RED_LED_PIN GPIO_PIN_8
#define BLUE_LED_GPIO GPIOB
#define BLUE_LED_PIN GPIO_PIN_7
#define GREEN_LED_GPIO GPIOB
#define GREEN_LED_PIN GPIO_PIN_6
#define R1_PIN GPIOA_PIN_6
#define R2_PIN GPIOB_PIN_0
#define L1_PIN GPIOB_PIN_12
#define L2_PIN GPIOB_PIN_15
#define M_PIN GPIOB_PIN_13
#define Beep_GPIO GPIOA
#define Beep_PIN GPIO_PIN_12

#define TRIG_GPIO GPIOD
#define TRIG_PIN GPIO_PIN_2 //trig??????
#define ECHO_GPIO GPIOB
#define ECHO_PIN GPIO_PIN_3 //echo??????

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
int fputc(int ch, FILE *f)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
  return ch; 
}


int countl = 0;
int count2 =0;
int distance=0;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
void ctrl_led(GPIO_PinState PinState)
{
    HAL_GPIO_WritePin(RED_LED_GPIO,RED_LED_PIN,PinState);
    HAL_GPIO_WritePin(BLUE_LED_GPIO,BLUE_LED_PIN,PinState);
    HAL_GPIO_WritePin(GREEN_LED_GPIO,GREEN_LED_PIN,PinState);
    
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef*htim)
{
    if(htim==&htim6)
        {
              //����Ƕ�ʱ��6��ʱʱ�䵽�ˣ�����������
            //��������������ʼ�ź�
            //4����tirg����
            //5���жϴ�tim7
					HAL_GPIO_WritePin(TRIG_GPIO,TRIG_PIN,GPIO_PIN_SET);
          HAL_TIM_Base_Start_IT(&htim7);
					
        }
        if(htim==&htim7)   //�Ƿ�ʱ��7��ʱʱ�䵽��
        {
              //�ر�tim7
                //����tirg����
					HAL_TIM_Base_Stop_IT(&htim7);
         HAL_GPIO_WritePin(TRIG_GPIO,TRIG_PIN,GPIO_PIN_RESET);
        }
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_PIN)
{
    if(GPIO_PIN==ECHO_PIN)//9�ж��Ƿ���ECHO_PIN������
        {
                //10�ж��Ƿ��������ش�����
            if(1==HAL_GPIO_ReadPin(ECHO_GPIO,ECHO_PIN))//��echo���Ŵ�ʱ�Ƿ�Ϊ�ߵ�ƽ
            {
                 countl=__HAL_TIM_GET_COUNTER(&htim6);//��һ�������������ʱ��tim6�����Ĵ�����ֵ
            }
            else//12��ʱΪ�½��ش���
            {
                //13������һ��������count2):�����ʱtim6�����Ĵ�����ֵ
              count2=__HAL_TIM_GET_COUNTER(&htim6);  
							//14��һ����������distance��������ľ���ǰ���ϰ���ľ���
              distance=(count2-countl)*17/10;  
							printf("����Ϊ��%d\n",distance);
            }
					}
}
void Beep()
{
	HAL_GPIO_WritePin(Beep_GPIO,Beep_PIN,GPIO_PIN_SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(Beep_GPIO,Beep_PIN,GPIO_PIN_RESET);
}

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
  MX_TIM6_Init();
  MX_USART1_UART_Init();
  MX_TIM7_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	
	
//	 char m[5];
//	 int l1;
//	 int l2;
//	 int r1;
//	 int r2;
//	 int mid;


	//�򿪶�ʱ��6
 HAL_TIM_Base_Start_IT(&htim6);  //�򿪶�ʱ��6
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  	  ctrl_led(GPIO_PIN_SET);
  while (1)
  {
		
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
//    ctrl_led(GPIO_PIN_SET);
//		HAL_Delay(1000);
//		ctrl_led(GPIO_PIN_RESET);
//		HAL_Delay(1000);
//

	
//	  HAL_UART_Receive(&huart1,m,5,0xFFFFFFFF);
//	  int i=strncmp(m,"ledon",5);
//	  int h=strncmp(m,"ledof",5);
//	  if(0==i)
//	  { 
//			ctrl_led(GPIO_PIN_RESET);
//		    HAL_UART_Transmit(&huart1,m,5,0xFFFFFFFF);
//	  }
//	   if(0==h)		  
//	  {
//			ctrl_led(GPIO_PIN_SET);
//		    HAL_UART_Transmit(&huart1,m,5,0xFFFFFFFF);
//	  }
	  
/*  
	  l1 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12);
	  l2 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_15);
	  r1 = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6);
	  r2 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
	  mid = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_13);
	  if (1 == mid)
	  {
		printf("ֱ��\n");//ֱ��
		Beep();
	  }
	  else 
	  {
	  
	  }
		if(1 == r1)
	  {
		printf("����ת\n");//����ת
		Beep();
	  }
	   else 
	  {
	  
	  }
	  if(1 == r2)
	  {
		printf("����ת\n");//����ת
		Beep();
	  }
	   else 
	  {
	  
	  }
	  if(1 == l1)
	  {
		printf("����ת\n");//����ת
		Beep();
	  }
	   else 
	  {
	  
	  }
	  if(1 == l2)
	  {
		printf("����ת\n");//����ת
		Beep();
	  }
	   else 
	  {
	  
	  }
	  
*/


//	  HAL_UART_Transmit(&huart1,m,5,0xFFFFFFFF);
		
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/*
void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef * htim)
{
	
  if(htim==&htim6)
  {
//		GPIOB->ODR^=GPIO_PIN_6;
//		GPIOB->ODR^=GPIO_PIN_7;
//		GPIOB->ODR^=GPIO_PIN_8;
   }
}
*/

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
