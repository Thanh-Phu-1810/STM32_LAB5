/*
 * command_parser_fsm.h
 *
 *  Created on: Nov 13, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_COMMAND_PARSER_FSM_H_
#define INC_COMMAND_PARSER_FSM_H_

#include "main.h"
#include "stdio.h"
#include "string.h"

#define MAX_BUFFER_SIZE 30
#define INIT            0
#define CHECK           1
#define END             2

extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t temp;
extern int status;
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
//extern uint32_t ADC_value;
extern uint32_t command_flag;
void command_parser_fsm();

#endif /* INC_COMMAND_PARSER_FSM_H_ */


