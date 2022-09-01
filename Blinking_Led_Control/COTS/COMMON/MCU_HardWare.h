
#ifndef MCU_HARDWARE_H_
#define MCU_HARDWARE_H_

#define SYSCTL_RCGCGPIO_REG       (*((volatile uint32 *)0x400FE608))

/************************************************************************/
/* GPIO A REGISTERS                                                     */
/************************************************************************/
 #define GPIO_PORTA_DATA_REG       (*((volatile uint32 *)0x400043FC))
 #define GPIO_PORTA_DIR_REG        (*((volatile uint32 *)0x40004400))
 #define GPIO_PORTA_AFSEL_REG      (*((volatile uint32 *)0x40004420))
 #define GPIO_PORTA_ODR_R        (*((volatile uint32 *)0x4000450C))
 #define GPIO_PORTA_PUR_R        (*((volatile uint32 *)0x40004510))
 #define GPIO_PORTA_PDR_R        (*((volatile uint32 *)0x40004514))
 #define GPIO_PORTA_DEN_REG        (*((volatile uint32 *)0x4000451C))
 #define GPIO_PORTA_LOCK_REG       (*((volatile uint32 *)0x40004520))
 #define GPIO_PORTA_CR_REG         (*((volatile uint32 *)0x40004524))
 #define GPIO_PORTA_AMSEL_REG      (*((volatile uint32 *)0x40004528))
 #define GPIO_PORTA_PCTL_REG       (*((volatile uint32 *)0x4000452C))

/************************************************************************/
/* GPIO F REGISTERS                                                     */
/************************************************************************/
#define GPIO_PORTF_DATA_REG       (*((volatile uint32 *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile uint32 *)0x40025400))
#define GPIO_PORTF_IS_R         (*((volatile uint32 *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile uint32 *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile uint32 *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile uint32 *)0x40025410))
#define GPIO_PORTF_RIS_R        (*((volatile uint32 *)0x40025414))
#define GPIO_PORTF_MIS_R        (*((volatile uint32 *)0x40025418))
#define GPIO_PORTF_ICR_R        (*((volatile uint32 *)0x4002541C))
#define GPIO_PORTF_AFSEL_REG      (*((volatile uint32 *)0x40025420))
#define GPIO_PORTF_ODR_R        (*((volatile uint32 *)0x4002550C))
#define GPIO_PORTF_PUR_R        (*((volatile uint32 *)0x40025510))
#define GPIO_PORTF_PDR_R        (*((volatile uint32 *)0x40025514))
#define GPIO_PORTF_SLR_R        (*((volatile uint32 *)0x40025518))
#define GPIO_PORTF_DEN_REG        (*((volatile uint32 *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile uint32 *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile uint32 *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile uint32 *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile uint32 *)0x4002552C))

/************************************************************************/
/* TIMER0 REGISTERS                                                   */
/************************************************************************/
#define SYSCTL_RCGCTIMER_REG      (*((volatile uint32 *)0x400FE604))
#define TIMER0_CFG_REG            (*((volatile uint32 *)0x40030000))
#define TIMER0_TAMR_REG           (*((volatile uint32 *)0x40030004))
#define TIMER0_CTL_REG            (*((volatile uint32 *)0x4003000C))       
#define TIMER0_IMR_REG            (*((volatile uint32 *)0x40030018))
#define TIMER0_TAILR_REG          (*((volatile uint32 *)0x40030028))
#define TIMER0_ICR_REG            (*((volatile uint32 *)0x40030024))
#define TIMER0_RIS_REG            (*((volatile uint32 *)0x4003001C))



#define GPIODATA(x)	*((volatile uint32*)(GPIO_OFFSET(x)))
#define GPIODIR(x)	*((volatile uint32*)(GPIO_OFFSET(x)+ 0x400))
/*    ///////////////////////////////////////////////////   */
#define GPIO_OFFSET(x)		    (x<4?((0x40004000)+((x)*0x1000)):((0x40020000)+((x)*0x1000)))

#define GPIODATA(x)	    *((volatile uint32*)(GPIO_OFFSET(x)))
#define GPIODIR(x)	    *((volatile uint32*)(GPIO_OFFSET(x)+ 0x0400))
#define GPIOIS(x)		*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0404))
#define GPIOIBE(x)		*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0408))
#define GPIOIEV(x)		*((volatile uint32*)(GPIO_OFFSET(x)+ 0x040C))
#define GPIOIM(x)		*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0410))
#define GPIORIS(x)		*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0414))
#define GPIOMIS(x)		*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0418))
#define GPIOICR(x)		*((volatile uint32*)(GPIO_OFFSET(x)+ 0x041C))
#define GPIOAFSEL(x)    *((volatile uint32*)(GPIO_OFFSET(x)+ 0x0420))
#define GPIODR2R(x) 	*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0500))
#define GPIODR4R(x) 	*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0504))
#define GPIODR8R(x)   	*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0508))
#define GPIOODR(x)  	*((volatile uint32*)(GPIO_OFFSET(x)+ 0x050C))
#define GPIOPUR(x)		*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0510))
#define GPIOPDR(x) 	    *((volatile uint32*)(GPIO_OFFSET(x)+ 0x0514))
#define GPIOSLR(x)		*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0518))
#define GPIODEN(x) 	    *((volatile uint32*)(GPIO_OFFSET(x)+ 0x051C))
#define GPIOLOCK(x)	    *((volatile uint32*)(GPIO_OFFSET(x)+ 0x0520))
#define GPIOCR(x)		*((volatile uint32*)(GPIO_OFFSET(x)+ 0x0524))
/*
#define GPIO_PORT_A_OFFSET      0x40004000
#define GPIO_PORT_B_OFFSET      0x40005000
#define GPIO_PORT_C_OFFSET      0x40006000
#define GPIO_PORT_D_OFFSET      0x40007000
#define GPIO_PORT_E_OFFSET      0x40024000
#define GPIO_PORT_F_OFFSET      0x40025000
*/

/** Interrupt IDs*/
#define  NVIC_GPIOA_ID                                                 0
#define  NVIC_GPIOB_ID                                                 1
#define  NVIC_GPIOC_ID                                                 2
#define  NVIC_GPIOD_ID                                                 3
#define  NVIC_GPIOE_ID                                                 4
#define  NVIC_UART0_ID                                                 5
#define  NVIC_UART1_ID                                                 6
#define  NVIC_SSI0_ID                                                  7
#define  NVIC_I2C0_ID                                                  8
#define  NVIC_PWM0_FAULT_ID                                            9
#define  NVIC_PWM0_GENERATOR0_ID                                       10
#define  NVIC_PWM0_GENERATOR1_ID                                       11
#define  NVIC_PWM0_GENERATOR2_ID                                       12
#define  NVIC_QEI0_ID                                                  13
#define  NVIC_ADC0_SEQUENCE0_ID                                        14
#define  NVIC_ADC0_SEQUENCE1_ID                                        15
#define  NVIC_ADC0_SEQUENCE2_ID                                        16
#define  NVIC_ADC0_SEQUENCE3_ID                                        17
#define  NVIC_WATCHFOG_TIMERS0_AND_1_ID                                18
#define  NVIC_16_32_BIT_TIMER_0A_ID                                    19
#define  NVIC_16_32_BIT_TIMER_0B_ID                                    20
#define  NVIC_16_32_BIT_TIMER_1A_ID                                    21
#define  NVIC_16_32_BIT_TIMER_1B_ID                                    22
#define  NVIC_16_32_BIT_TIMER_2A_ID                                    23
#define  NVIC_16_32_BIT_TIMER_2B_ID                                    24
#define  NVIC_ANALOG_COMPARATOR_0_ID                                   25
#define  NVIC_ANALOG_COMPARATOR_1_ID                                   26
#define  NVIC_SYSTEM_CONTROL_ID                                        28
#define  NVIC_FLASH_AND_EEPROM_CONTROL_ID                              29
#define  NVIC_GPIO_F_ID                                                30
#define  NVIC_UART2_ID                                                 33
#define  NVIC_SSI1_ID                                                  34
#define  NVIC_16_32_BIT_TIMER_3A_ID                                    35
#define  NVIC_16_32_BIT_TIMER_3B_ID                                    36
#define  NVIC_I2C1_ID                                                  37
#define  NVIC_QEI1_ID                                                  38
#define  NVIC_CAN0_ID                                                  39
#define  NVIC_CAN1_ID                                                  40
#define  NVIC_HIBERNATION_MODULE_ID                                    43
#define  NVIC_USB_ID                                                   44
#define  NVIC_PWM_GENERATOR_3_ID                                       45
#define  NVIC_MICRO_DMA_SOFTWARE_ID                                    46
#define  NVIC_MICRO_DMA_ERROE_ID                                       47
#define  NVIC_ADC1_SEQUENCE_0_ID                                       48
#define  NVIC_ADC1_SEQUENCE_1_ID                                       49
#define  NVIC_ADC1_SEQUENCE_2_ID                                       50
#define  NVIC_ADC1_SEQUENCE_3_ID                                       51
#define  NVIC_SSI2_ID                                                  57
#define  NVIC_SSI3_ID                                                  58
#define  NVIC_UART3_ID                                                 59
#define  NVIC_UART4_ID                                                 60
#define  NVIC_UART5_ID                                                 61
#define  NVIC_UART6_ID                                                 62
#define  NVIC_UART7_ID                                                 63
#define  NVIC_I2C2_ID                                                  68
#define  NVIC_I2C3_ID                                                  69
#define  NVIC_16_32_BIT_TIMER_4A_ID                                    70
#define  NVIC_16_32_BIT_TIMER_4B_ID                                    71
#define  NVIC_16_32_BIT_TIMER_5A_ID                                    92
#define  NVIC_16_32_BIT_TIMER_5B_ID                                    93
#define  NVIC_32_64_BIT_TIMER_0A_ID                                    94
#define  NVIC_32_64_BIT_TIMER_0B_ID                                    95
#define  NVIC_32_64_BIT_TIMER_1A_ID                                    96
#define  NVIC_32_64_BIT_TIMER_1B_ID                                    97
#define  NVIC_32_64_BIT_TIMER_2A_ID                                    98
#define  NVIC_32_64_BIT_TIMER_2B_ID                                    99
#define  NVIC_32_64_BIT_TIMER_3A_ID                                    100
#define  NVIC_32_64_BIT_TIMER_3B_ID                                    101
#define  NVIC_32_64_BIT_TIMER_4A_ID                                    102
#define  NVIC_32_64_BIT_TIMER_4B_ID                                    103
#define  NVIC_32_64_BIT_TIMER_5A_ID                                    104
#define  NVIC_32_64_BIT_TIMER_5B_ID                                    105
#define  NVIC_SYSTEM_EXCEPTION_ID                                      106
#define  NVIC_PWM1_GENERATOR_0_ID                                      134
#define  NVIC_PWM1_GENERATOR_1_ID                                      135
#define  NVIC_PWM1_GENERATOR_2_ID                                      136
#define  NVIC_PWM1_GENERATOR_3_ID                                      137
#define  NVIC_PWM1_FAULT_ID


/*****************************************************************************
//
// NVIC registers (NVIC)
//
*****************************************************************************/
#define NVIC_EN0              (*((volatile uint32 *)0xE000E100))
#define NVIC_EN1              (*((volatile uint32 *)0xE000E104))
#define NVIC_EN2              (*((volatile uint32 *)0xE000E108))
#define NVIC_EN3              (*((volatile uint32 *)0xE000E10C))
#define NVIC_EN4              (*((volatile uint32 *)0xE000E110))
#define NVIC_DIS0             (*((volatile uint32 *)0xE000E180))
#define NVIC_DIS1             (*((volatile uint32 *)0xE000E184))
#define NVIC_DIS2             (*((volatile uint32 *)0xE000E188))
#define NVIC_DIS3             (*((volatile uint32 *)0xE000E18C))
#define NVIC_DIS4             (*((volatile uint32 *)0xE000E190))

#endif /* MCU_HARDWARE_H_ */