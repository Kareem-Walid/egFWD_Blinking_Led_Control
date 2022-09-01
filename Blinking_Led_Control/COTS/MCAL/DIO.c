/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.c
 *       Module:  DIO
 *
 *  Description:  Source  file for DIO Module    
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DIO.h" 
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void DIO_PortInit(PortConfigTypes PortConfig)
{
	SYSCTL_RCGCGPIO_REG  |= PortConfig.Port_clock;                  //init for port F 0x00001000
	while ((SYSCTL_RCGCGPIO_REG &  PortConfig.Port_clock  ) == 0)   // port F  ready
	GPIO_PORTF_LOCK_REG = 0x4C4F434B ;           // lock --> cons value
	GPIO_PORTF_CR_REG = PortConfig.CommitPins ;            // commit register	 --> allow changes in all pins  --> 0xff
	// GPIO_PORTF_AMSEL_REG = ;             //  disable analog on PD
	GPIO_PORTF_PCTL_REG = PortConfig.PCTL;                     // PCTL GPIO on PE7-PE0
	GPIO_PORTF_DIR_REG =  PortConfig.PortDirection;           //   PF7-4 in, PF3-0 out  --> 0x0f
	GPIO_PORTF_AFSEL_REG = PortConfig.Port_Mode;    //  disable alt funct on PF7-0 --> 0x00
	GPIO_PORTF_DEN_REG = 0xff;              // enable digital I/O on PF7-0
}
/******************************************************************************
* \Syntax          : DIO_PinLevel DIO_ReadChannel(DIO_PinConfig ChannelID)
* \Description     : Read GPIO Channel(Pin)
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : DIO_PinConfig ChannelID
* \Parameters (out): DIO_PinLevel
* \Return value:   : return Level of the Pin High or Low 
*******************************************************************************/
DIO_PinLevel DIO_ReadChannel(DIO_PinConfig ChannelID)
{
	return READ_BIT(GPIODATA(ChannelID.Port),ChannelID.Pin);
}


/******************************************************************************
* \Syntax          : void DIO_WriteChannel(DIO_PinConfig ChannelID)
* \Description     :  Write on a Channel 
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : DIO_PinConfig ChannelID
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void DIO_WriteChannel(DIO_PinConfig ChannelID)
{
	
	if ( ChannelID.level == HIGH )
	{
		SET_BIT(GPIODATA(ChannelID.Port),ChannelID.Pin);
	}else
	{
		CLR_BIT(GPIODATA(ChannelID.Port),ChannelID.Pin);
	}
}

/******************************************************************************
* \Syntax          : DIO_PortValue DIO_ReadPort(DIO_Port PortID)
* \Description     : 
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : DIO_Port PortID
* \Parameters (out): DIO_PortValue
* \Return value:   : The Value from 0 to 255
*******************************************************************************/

DIO_PortValue DIO_ReadPort(DIO_Port PortID)
{
	return GPIODATA(PortID);
}

/******************************************************************************
* \Syntax          : void DIO_WritePort(DIO_Port PortID ,DIO_PortValue val)
* \Description     :
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : DIO_Port PortID ,DIO_PortValue val
* \Parameters (out): None
* \Return value:   : None
******************************************************************************/
void DIO_WritePort(DIO_Port PortID ,DIO_PortValue val)
{
	GPIODATA(PortID) = val;
}


/******************************************************************************
* \Syntax          : DIO_PinLevel DIO_FlopChannel(DIO_PinConfig ChannelID)
* \Description     :
*
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : DIO_PinConfig ChannelID
* \Parameters (out): DIO_PinLevel
* \Return value:   : the value high or low
*******************************************************************************/

DIO_PinLevel DIO_FlopChannel(DIO_PinConfig ChannelID)

{
	TOGGLE_BIT(GPIODATA(ChannelID.Port),ChannelID.Pin);
	return DIO_ReadChannel(ChannelID);
}

/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/