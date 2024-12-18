/*
 * uart_communiation_fsm.h
 *
 *  Created on: Nov 13, 2024
 *      Author: Thanh Phu
 */

#ifndef INC_UART_COMMUNIATION_FSM_H_
#define INC_UART_COMMUNIATION_FSM_H_

#include "main.h"
#include "stdio.h"
#include "string.h"

#define TIMEOUT 3000
extern uint32_t last_time;
extern UART_HandleTypeDef huart2;
extern uint32_t ADC_value;
extern uint8_t waiting;
void uart_communiation_fsm();
void read_adc_value();
#endif /* INC_UART_COMMUNIATION_FSM_H_ */









