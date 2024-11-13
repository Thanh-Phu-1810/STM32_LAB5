/*
 * command_parser_fsm.c
 *
 *  Created on: Nov 13, 2024
 *      Author: Thanh Phu
 */

#include "command_parser_fsm.h"
void command_parser_fsm()
{
	if(strstr((char *)buffer, "!RST#") != NULL)
	{
		char str[50];
		sprintf(str, "!ADC=%lu#", ADC_value);
		HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
		memset(buffer, 0 , MAX_BUFFER_SIZE);
		index_buffer = 0;
	}
	else if(strstr((char *)buffer, "!OK#") != NULL)
	{
		HAL_UART_Transmit(&huart2, (uint8_t *)"!OK#", 4, 1000);
		memset(buffer, 0, MAX_BUFFER_SIZE);
		index_buffer = 0;
	}
}
