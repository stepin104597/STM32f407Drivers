/*
 * stm32f407.gpio.driver.h
 *
 *  Created on: 30-Sep-2020
 *      Author: Training
 */


#ifndef INC_STM32F407_GPIO_DRIVER_H_
#define INC_STM32F407_GPIO_DRIVER_H_

#include "stm32f407.h"
#include <stdint.h>
typedef struct
{
 uint8_t GPIO_PinNumber;
 uint8_t GPIO_PinMode;
 uint8_t GPIO_PinSpeed;
 uint8_t GPIO_PinOPType;
 uint8_t GPIO_PinPuPdControl;
 uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

typedef struct
{
	GPIO_REGDEF_t *pGPIOx;
	GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_HANDLE_t;

       //GPIO_PinNumber of GPIOx
#define GPIO_Pin_No_0              0
#define GPIO_Pin_No_1              1
#define GPIO_Pin_No_2              2
#define GPIO_Pin_No_3              3
#define GPIO_Pin_No_4              4
#define GPIO_Pin_No_5              5
#define GPIO_Pin_No_6              6
#define GPIO_Pin_No_7              7
#define GPIO_Pin_No_8              8
#define GPIO_Pin_No_9              9
#define GPIO_Pin_No_10            10
#define GPIO_Pin_No_11            11
#define GPIO_Pin_No_12            12
#define GPIO_Pin_No_13            13
#define GPIO_Pin_No_14            14
#define GPIO_Pin_No_15            15
       //GPIO_PinMode of GPIOx
#define GPIO_Pin_Mode_Input        0
#define GPIO_Pin_Mode_Output       1
#define GPIO_Pin_Mode_AltFunc      2
#define GPIO_Pin_Mode_Analog       3
       //GPIO_Pin_Speed of GPIOx
#define GPIO_Pin_Speed_Low         0
#define GPIO_Pin_Speed_Medium      1
#define GPIO_Pin_Speed_High        2
#define GPIO_Pin_Speed_VeryHigh    3
       //GPIO_Pin_OPType
#define GPIO_Pin_OPType_PP         0
#define GPIO_Pin_OPType_OD         1
       //GPIO_Pin_PuPdControl of GPIOx
#define GPIO_Pin_PuPdControl_NoPuPd     0
#define GPIO_Pin_PuPdControl_PullUp     1
#define GPIO_Pin_PuPdControl_PullDown   2
#define GPIO_Pin_PuPdControl_Reserved   3
       //GPIO_Pin_AltFunMode of GPIOx

void GPIO_Init(GPIO_HANDLE_t *GPIOHandle);                          //Initialization
void GPIO_DInit(GPIO_REGDEF_t *pGPIOx);                             //De-initialization
void GPIO_PeriClkCtr(GPIO_REGDEF_t *pGPIOx,uint8_t EnOrDi);
uint8_t GPIO_ReadFromInputPin(GPIO_REGDEF_t *pGPIOx, uint8_t PinNo);
uint16_t GPIO_ReadFromInputPort(GPIO_REGDEF_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNo,uint8_t value);
void GPIO_WriteTOOutputPort(GPIO_REGDEF_t *pGPIOx,uint16_t value);
void GPIO_ToggleOutputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNo);

#endif /* INC_STM32F407_GPIO_DRIVER_H_ */
