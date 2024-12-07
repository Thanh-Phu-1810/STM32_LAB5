/*
 * uart_communiation_fsm.c
 *
 *  Created on: Nov 13, 2024
 *      Author: Thanh Phu
 */
#include "uart_communiation_fsm.h"
#include "command_parser_fsm.h"
uint32_t last_time = 0;
uint8_t waiting = 0;
//UART_State state = IDLE;
void uart_communiation_fsm()
{
	switch(command_flag)
	{
		case 0:
			if(waiting && (HAL_GetTick() - last_time >= TIMEOUT))
			{
				char str[50];
				sprintf(str, "!ADC=%lu#\r\n", ADC_value);
				HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
				last_time = HAL_GetTick();
			}
			break;
		case 1:
			last_time = HAL_GetTick();
			char str[50];
			sprintf(str, "\r\n!ADC=%lu#\r\n", ADC_value);
			HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
			command_flag = 0;
			waiting = 1;
			break;
		case 2:
			HAL_UART_Transmit(&huart2, (uint8_t *)"\r\n!END", 6, 1000);
			command_flag = 3;
			waiting = 0;
			break;
		default:
			waiting = 0;
			break;
	}
//	if(command_flag == 1)
//	{
//		last_time = HAL_GetTick();
//		char str[50];
//		sprintf(str, "!ADC=%lu#\r\n", ADC_value);
//		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
//		waiting = 1;
//		command_flag = 0;
//	}
//	else if(command_flag == 2)
//	{
//		waiting = 0;
//	}
//	if(waiting == 1)
//	{
//		if(HAL_GetTick() - last_time >= TIMEOUT)
//		{
//			char str[50];
//			sprintf(str, "!ADC=%lu#", ADC_value);
//			HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
//			last_time = HAL_GetTick();
//		}
//	}
}

