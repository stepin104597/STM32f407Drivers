/*
 * stm32f407.gpio.driver.c
 *
 *  Created on: 30-Sep-2020
 *      Author: Training
 */

#include"stm32f407.gpio.driver.h"
#include "stm32f407.h"
/*
 * @Brief Description
 * @Function-
 * @Param1-
 *
 * @Param2-
 *
 * @Param3-
 *
 * @Definition
 *
 *
 * @Design by -
 *
 * @Date and Time-
 *
 */
void GPIO_PeriClkCtr(GPIO_REGDEF_t *pGPIOx,uint8_t EnOrDi)
{
	if(EnOrDi==ENABLE)
	{
	if(pGPIOx==GPIOA)
	{
		GPIOA_PCLK_EN();
	}
	else if(pGPIOx==GPIOB)
	{
		GPIOB_PCLK_EN();
	}
	else if(pGPIOx==GPIOC)
		{
			GPIOC_PCLK_EN();
		}
	else if(pGPIOx==GPIOD)
		{
			GPIOD_PCLK_EN();
		}
	else if(pGPIOx==GPIOE)
		{
			GPIOE_PCLK_EN();
		}
	else if(pGPIOx==GPIOF)
		{
			GPIOF_PCLK_EN();
		}
	else if(pGPIOx==GPIOG)
		{
			GPIOG_PCLK_EN();
		}
	else if(pGPIOx==GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	else if(pGPIOx==GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{
		{
			if(pGPIOx==GPIOA)
			{
				GPIOA_PCLK_DI();
			}
			else if(pGPIOx==GPIOB)
			{
				GPIOB_PCLK_DI();
			}
			else if(pGPIOx==GPIOC)
				{
					GPIOC_PCLK_DI();
				}
			else if(pGPIOx==GPIOD)
				{
					GPIOD_PCLK_DI();
				}
			else if(pGPIOx==GPIOE)
				{
					GPIOE_PCLK_DI();
				}
			else if(pGPIOx==GPIOF)
				{
					GPIOF_PCLK_DI();
				}
			else if(pGPIOx==GPIOG)
				{
					GPIOG_PCLK_DI();
				}
			else if(pGPIOx==GPIOH)
				{
					GPIOH_PCLK_DI();
				}
			else if(pGPIOx==GPIOI)
				{
					GPIOI_PCLK_DI();
				}
			}
	}
}
/*
 * @Brief Description
 * @Function-
 * @Param1-
 *
 * @Param2-
 *
 * @Param3-
 *
 * @Definition
 *
 *
 * @Design by -
 *
 * @Date and Time-
 *
 */
void GPIO_Init(GPIO_HANDLE_t *GPIOHandle)
{
	//Init MODE
	uint32_t temp=0;
	temp=(GPIOHandle->GPIO_PinConfig.GPIO_PinMode<<(2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->MODER) &= ~(0x3<<(2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->MODER) |= temp;

	//Confi Speed
	temp=0;
	temp=(GPIOHandle->GPIO_PinConfig.GPIO_PinSpeed<<(2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->OSPEEDR) &= ~(0x3<<(2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->OSPEEDR) |= temp;

	//Confi PUPD
	temp=0;
	temp=(GPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl<<(2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->PUPDR) &= ~(0x3<<(2*GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->PUPDR) |= temp;

	//conf Output type
	temp=0;
	temp=(GPIOHandle->GPIO_PinConfig.GPIO_PinOPType<<(GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->OTYPER) &= ~(0x1<<(GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	(GPIOHandle->pGPIOx->OTYPER) |= temp;

	//Conf Alt Func
    temp=0;
    if(GPIOHandle->GPIO_PinConfig.GPIO_PinMode==GPIO_Pin_Mode_AltFunc)
    {
    	uint8_t temp1=0,temp2=0;
    	temp1=(GPIOHandle->GPIO_PinConfig.GPIO_PinNumber)/8;
    	temp2=(GPIOHandle->GPIO_PinConfig.GPIO_PinNumber)%8;
    	GPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF<<temp2);
       (GPIOHandle->pGPIOx->AFR[temp1]) |= GPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode<<(4*temp2);
    }
}
/*
 * @Brief Description
 * @Function-
 * @Param1-
 *
 * @Param2-
 *
 * @Param3-
 *
 * @Definition
 *
 *
 * @Design by -
 *
 * @Date and Time-
 *
 */
void GPIO_DInit(GPIO_REGDEF_t *pGPIOx)
{
	if(pGPIOx==GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if (pGPIOx==GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if (pGPIOx==GPIOC)
		{
			GPIOC_REG_RESET();
		}
	else if (pGPIOx==GPIOD)
		{
			GPIOD_REG_RESET();
		}
	else if (pGPIOx==GPIOE)
		{
			GPIOE_REG_RESET();
		}
	else if (pGPIOx==GPIOF)
		{
			GPIOF_REG_RESET();
		}
	else if (pGPIOx==GPIOG)
		{
			GPIOG_REG_RESET();
		}
	else if (pGPIOx==GPIOH)
		{
			GPIOH_REG_RESET();
		}
	else if (pGPIOx==GPIOI)
		{
			GPIOI_REG_RESET();
		}
}
/*
 * @Brief Description
 * @Function-
 * @Param1-
 *
 * @Param2-
 *
 * @Param3-
 *
 * @Definition
 *
 *
 * @Design by -
 *
 * @Date and Time-
 *
 */
uint8_t GPIO_ReadFromInputPin(GPIO_REGDEF_t *pGPIOx, uint8_t PinNo)
{
	uint8_t value=0;
	value=(uint8_t)(pGPIOx->IDR>>PinNo)&(0x00000001);
	return value;
}
/*
 * @Brief Description
 * @Function-
 * @Param1-
 *
 * @Param2-
 *
 * @Param3-
 *
 * @Definition
 *
 *
 * @Design by -
 *
 * @Date and Time-
 *
 */
uint16_t GPIO_ReadFromInputPort(GPIO_REGDEF_t *pGPIOx)
{
	uint16_t value=0;
	value=(uint16_t)(pGPIOx->IDR);
	return value;
}
/*
 * @Brief Description
 * @Function-
 * @Param1-
 *
 * @Param2-
 *
 * @Param3-
 *
 * @Definition
 *
 *
 * @Design by -
 *
 * @Date and Time-
 *
 */
void GPIO_WriteToOutputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNo,uint8_t value)
{
	if(value==GPIO_Pin_set)
	{
		pGPIOx->ODR &= ~(1<<PinNo);
		pGPIOx->ODR |= (1<<PinNo);
	}
	else
	{
		pGPIOx->ODR &= ~(1<<PinNo);
	}
}
/*
 * @Brief Description
 * @Function-
 * @Param1-
 *
 * @Param2-
 *
 * @Param3-
 *
 * @Definition
 *
 *
 * @Design by -
 *
 * @Date and Time-
 *
 */
void GPIO_WriteTOOutputPort(GPIO_REGDEF_t *pGPIOx,uint16_t value)
{
	pGPIOx->ODR=value;
}
/*
 * @Brief Description
 * @Function-
 * @Param1-
 *
 * @Param2-
 *
 * @Param3-
 *
 * @Definition
 *
 *
 * @Design by -
 *
 * @Date and Time-
 *
 */
void GPIO_ToggleOutputPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNo)
{
	pGPIOx->ODR ^=(1<<PinNo);
}
