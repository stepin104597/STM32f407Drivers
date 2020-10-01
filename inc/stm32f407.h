/*
 * stm32f407.h
 *
 *  Created on: Sep 29, 2020
 *      Author: Training
 */
#ifndef INC_STM32F407_H_
#define INC_STM32F407_H_


#include <stdint.h>
        //BASE ADDRESSES OF MEMORY
#define FLASH_BASE_ADDR    			   0x08000000UL
#define ROM_BASE_ADDR       		   0x1FFF0000UL
#define SRAM1_BASE_ADDR     		   0x20000000UL
#define SRAM2_BASE_ADDR    			   0x2001C000UL
#define SRAM                           SRAM1_BASE_ADDR
        //BASE ADDRESSES OF BUSES
#define PERIPH_BASE_ADDR               0x40000000UL
#define APB1_BASE_ADDR      		   PERIPH_BASE_ADDR
#define APB2_BASE_ADDR      		   0x40010000UL
#define AHB1_BASE_ADDR      		   0x40020000UL
#define AHB2_BASE_ADDR      	 	   0x50000000UL
        //BASE ADDRESSES OF PERIPHERALS HANGING ON AHB1
#define GPIOA_BASE_ADDR               (AHB1_BASE_ADDR + 0X00)
#define GPIOB_BASE_ADDR               (AHB1_BASE_ADDR + 0X0400)
#define GPIOC_BASE_ADDR               (AHB1_BASE_ADDR + 0X0800)
#define GPIOD_BASE_ADDR               (AHB1_BASE_ADDR + 0X0C00)
#define GPIOE_BASE_ADDR               (AHB1_BASE_ADDR + 0X1000)
#define GPIOF_BASE_ADDR               (AHB1_BASE_ADDR + 0X1400)
#define GPIOG_BASE_ADDR               (AHB1_BASE_ADDR + 0X1800)
#define GPIOH_BASE_ADDR               (AHB1_BASE_ADDR + 0X1C00)
#define GPIOI_BASE_ADDR               (AHB1_BASE_ADDR + 0X2000)
#define GPIOJ_BASE_ADDR               (AHB1_BASE_ADDR + 0X2400)
#define GPIOK_BASE_ADDR               (AHB1_BASE_ADDR + 0X2800)
#define RCC_BASE_ADDR                 (AHB1_BASE_ADDR + 0X3800)
        //BASE ADDRESSES OF PERIPHERALS HANGING ON APB1
#define SPI2_BASE_ADDR                (APB1_BASE_ADDR + 0X3800)
#define SPI3_BASE_ADDR                (APB1_BASE_ADDR + 0X3C00)
#define USART2_BASE_ADDR              (APB1_BASE_ADDR + 0X4400)
#define USART3_BASE_ADDR              (APB1_BASE_ADDR + 0X4800)
#define UART4_BASE_ADDR	 			  (APB1_BASE_ADDR + 0x4C00)
#define UART5_BASE_ADDR	 			  (APB1_BASE_ADDR + 0x5000)
#define I2C1_BASE_ADDR                (APB1_BASE_ADDR + 0X5400)
#define I2C2_BASE_ADDR                (APB1_BASE_ADDR + 0X5800)
#define I2C3_BASE_ADDR                (APB1_BASE_ADDR + 0X5C00)
        //BASE ADDRESSES OF PERIPHERALS HANGING ON APB2
#define USART1_BASE_ADDR              (APB2_BASE_ADDR + 0X1000)
#define USART6_BASE_ADDR              (APB2_BASE_ADDR + 0X1400)
#define SPI1_BASE_ADDR                (APB2_BASE_ADDR + 0X3000)
#define EXTI_BASE_ADDR                (APB2_BASE_ADDR + 0X3C00)
#define SYSCFG_BASE_ADDR              (APB2_BASE_ADDR + 0X3800)
        //REGISTER STRUCTURE OF GPIO PERIPHERAL
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_REGDEF_t;

       //PERIPHERAL DEFINATION
#define GPIOA ((GPIO_REGDEF_t*)GPIOA_BASE_ADDR)
#define GPIOB ((GPIO_REGDEF_t*)GPIOB_BASE_ADDR)
#define GPIOC ((GPIO_REGDEF_t*)GPIOC_BASE_ADDR)
#define GPIOD ((GPIO_REGDEF_t*)GPIOD_BASE_ADDR)
#define GPIOE ((GPIO_REGDEF_t*)GPIOE_BASE_ADDR)
#define GPIOF ((GPIO_REGDEF_t*)GPIOF_BASE_ADDR)
#define GPIOG ((GPIO_REGDEF_t*)GPIOG_BASE_ADDR)
#define GPIOH ((GPIO_REGDEF_t*)GPIOH_BASE_ADDR)
#define GPIOI ((GPIO_REGDEF_t*)GPIOI_BASE_ADDR)
#define GPIOJ ((GPIO_REGDEF_t*)GPIOJ_BASE_ADDR)
#define GPIOK ((GPIO_REGDEF_t*)GPIOK_BASE_ADDR)
       //REGISTER STRUCTURE OF RCC
typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    volatile uint32_t no1;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    volatile uint64_t no2;
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t no3;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    volatile uint64_t no4;
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t AHB3LPENR;
    volatile uint32_t no5;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    volatile uint64_t no6;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint64_t no7;
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t PLLSAICFGR;
    volatile uint32_t DCKCFGR;
}RCC_REGDEF_t;
        //RCC DEFINATION
#define RCC ((RCC_REGDEF_t*)RCC_BASE_ADDR)

//CLOCK ENABLE MACROS FOR GPIOX
#define GPIOA_PCLK_EN()        (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()        (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()        (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()        (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()        (RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN()        (RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN()        (RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN()        (RCC->AHB1ENR |= (1<<7))
#define GPIOI_PCLK_EN()        (RCC->AHB1ENR |= (1<<8))

//CLOCK DISABLE MACROS FOR GPIOX
#define GPIOA_PCLK_DI()        (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()        (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()        (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()        (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()        (RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI()        (RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI()        (RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI()        (RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DI()        (RCC->AHB1ENR &= ~(1<<8))

//Some Important Macros
#define ENABLE             		1
#define DISABLE					0
#define SET						ENABLE
#define RESET 					DISABLE
#define GPIO_Pin_set  			SET
#define GPIO_Pin_Reset			RESET

#define GPIOA_REG_RESET()      do{(RCC->AHB1RSTR |= (1<<0)); (RCC->AHB1RSTR &= ~(1<<0));}while(0)
#define GPIOB_REG_RESET()      do{(RCC->AHB1RSTR |= (1<<1)); (RCC->AHB1RSTR &= ~(1<<1));}while(0)
#define GPIOC_REG_RESET()      do{(RCC->AHB1RSTR |= (1<<2)); (RCC->AHB1RSTR &= ~(1<<2));}while(0)
#define GPIOD_REG_RESET() 	   do{(RCC->AHB1RSTR |= (1<<3)); (RCC->AHB1RSTR &= ~(1<<3));}while(0)
#define GPIOE_REG_RESET()	   do{(RCC->AHB1RSTR |= (1<<4)); (RCC->AHB1RSTR &= ~(1<<4));}while(0)
#define GPIOF_REG_RESET()	   do{(RCC->AHB1RSTR |= (1<<5)); (RCC->AHB1RSTR &= ~(1<<5));}while(0)
#define GPIOG_REG_RESET()      do{(RCC->AHB1RSTR |= (1<<6)); (RCC->AHB1RSTR &= ~(1<<6));}while(0)
#define GPIOH_REG_RESET()      do{(RCC->AHB1RSTR |= (1<<7)); (RCC->AHB1RSTR &= ~(1<<7));}while(0)
#define GPIOI_REG_RESET()      do{(RCC->AHB1RSTR |= (1<<8)); (RCC->AHB1RSTR &= ~(1<<8));}while(0)

#include"stm32f407.gpio.driver.h"
#endif /* INC_STM32F407_H_ */
