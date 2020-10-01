/*
 * 001LEDToggle.c
 *
 *  Created on: 01-Oct-2020
 *      Author: Training
 */

#include "stm32f407.h"
#include"stm32f407.gpio.driver.h"
#include <stdint.h>

/*void delay(void)
{
	for(uint32_t i=0;i<20000;i++);
}*/
int main(void)
{
	GPIO_HANDLE_t GPIOLed;
	GPIOLed.pGPIOx=GPIOD;
	GPIOLed.GPIO_PinConfig.GPIO_PinNumber=GPIO_Pin_No_12;
    GPIOLed.GPIO_PinConfig.GPIO_PinMode=GPIO_Pin_Mode_Output;
    GPIOLed.GPIO_PinConfig.GPIO_PinSpeed=GPIO_Pin_Speed_VeryHigh;
    GPIOLed.GPIO_PinConfig.GPIO_PinOPType=GPIO_Pin_OPType_PP;
    GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_Pin_PuPdControl_NoPuPd;
    GPIO_PeriClkCtr(GPIOD, ENABLE);
    GPIO_Init(&GPIOLed);

    GPIO_HANDLE_t Button;
    Button.pGPIOx=GPIOA;
    Button.GPIO_PinConfig.GPIO_PinNumber=GPIO_Pin_No_0;
    Button.GPIO_PinConfig.GPIO_PinMode=GPIO_Pin_Mode_Input;
    Button.GPIO_PinConfig.GPIO_PinSpeed=GPIO_Pin_Speed_VeryHigh;
    Button.GPIO_PinConfig.GPIO_PinPuPdControl=GPIO_Pin_PuPdControl_NoPuPd;
    GPIO_PeriClkCtr(GPIOA, ENABLE);
    GPIO_Init(&Button);

    while(1)
    {
    	if(GPIO_ReadFromInputPin(GPIOA,GPIO_Pin_No_0)==1)
    	{
    	 GPIO_WriteToOutputPin(GPIOD, GPIO_Pin_No_12, ENABLE);
    	}
    	else
    	{
    		GPIO_WriteToOutputPin(GPIOD, GPIO_Pin_No_12, DISABLE);
    	}
    }
    return 0;
}

