/*
 * uart_communiation_fsm.c
 *
 *  Created on: Nov 13, 2024
 *      Author: Thanh Phu
 */
#include "uart_communiation_fsm.h"
#include "command_parser_fsm.h"
uint32_t last_time = 0;
uint32_t waiting = 0;
//UART_State state = IDLE;
void uart_communiation_fsm()
{
//	char str[50];
//	switch(state){
//		case IDLE:
//			break;
//		case SEND_ADC:
//				sprintf(str, "!ADC=%lu#", ADC_value);
//				HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
//				state = WAIT_ACK;
//				//last_time = HAL_GetTick(); //do khoang thoi gian sau khi goi ham HAL_INIT, moi mili giay, gia tri dem cua HAL_GetTick() se tang len 1
//			break;
//		case WAIT_ACK:
//			if(HAL_GetTick() - last_time >= TIMEOUT)
//			{
//				state = SEND_ADC;
//				last_time = HAL_GetTick();
//			}
//			break;
//	}

	if(command_flag == 1)
	{
		last_time = HAL_GetTick();
		waiting = 1;
		command_flag = 0;
	}
	else if(command_flag == 2)
	{
		waiting = 0;
	}
	if(waiting == 1)
	{
		if(HAL_GetTick() - last_time >= TIMEOUT)
		{
			char str[50];
			sprintf(str, "!ADC=%lu#", ADC_value);
			HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
			last_time = HAL_GetTick();
		}
	}
}

