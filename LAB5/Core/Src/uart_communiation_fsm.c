/*
 * uart_communiation_fsm.c
 *
 *  Created on: Nov 13, 2024
 *      Author: Thanh Phu
 */
#include "uart_communiation_fsm.h"
UART_State state = IDLE;
uint32_t last_time = 0;
uint8_t ack_received = 0;

void uart_communiation_fsm()
{
	char str[50];
	switch(state){
		case IDLE:
			break;
		case SEND_ADC:
			sprintf(str, "!ADC=%lu#", ADC_value);
			HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);

			state = WAIT_ACK;
			last_time = HAL_GetTick(); //do khoang thoi gian sau khi goi ham HAL_INIT, moi mili giay, gia tri dem cua HAL_GetTick() se tang len 1
			ack_received = 0;
			break;
		case WAIT_ACK:
			if(ack_received)
			{
				state = IDLE;
			}
			if(HAL_GetTick() - last_time >= TIMEOUT)
			{
				state = SEND_ADC;
			}
			break;
	}
}

