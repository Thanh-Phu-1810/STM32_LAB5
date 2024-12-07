/*
 * command_parser_fsm.c
 *
 *  Created on: Nov 13, 2024
 *      Author: Thanh Phu
 */

#include "command_parser_fsm.h"
uint32_t command_flag = 3;
int status = INIT;
void command_parser_fsm()
{
//	if(strstr((char *)buffer, "!RST#") != NULL)
//	{
//		char str[50];
//		sprintf(str, "!ADC=%lu#\r\n", ADC_value);
//	    HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);//Truyền chuổi str qua UART2 để phản hồi lại cho các thiết bị gửi yêu cầu
//		memset(buffer, 0 , MAX_BUFFER_SIZE); //xóa nội dung của buffer
//		index_buffer = 0;
//		command_flag = 1;
//	}
//	else if(strstr((char *)buffer, "!OK#") != NULL)
//	{
//		HAL_UART_Transmit(&huart2, (uint8_t *)"!OK#", 4, 1000);
//		memset(buffer, 0, MAX_BUFFER_SIZE);
//		index_buffer = 0;
//		command_flag = 2;
//	}

	switch(status)
	{
		case INIT:
			if(buffer[0] == '!')
			{
				status = CHECK;
			}
			else index_buffer = 0;
			break;
		case CHECK:
				if(strncmp((char *)buffer, "!RST#", 5) == 0)
				{
					memset(buffer, 0, MAX_BUFFER_SIZE);
					command_flag = 1;
					index_buffer = 0;
					status = INIT;
				}
				else if(strncmp((char *)buffer, "!OK#", 4) == 0)
				{
					memset(buffer, 0, MAX_BUFFER_SIZE);
					command_flag = 2;
					index_buffer = 0;
					status = INIT;
				}
			break;
		default:
			status = INIT;
			index_buffer = 0;
			break;
}
}
