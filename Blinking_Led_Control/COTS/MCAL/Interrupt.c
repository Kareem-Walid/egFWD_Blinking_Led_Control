/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        Interrupt.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Interrupt.h"

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

/******************************************************************************
* \Syntax          : void NVIC_EnableInterrupt(uint8  InterruptID)
* \Description     : Enable Interrupt
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : InterruptID
* \Parameters (out): None
* \Return value:   : None  
*******************************************************************************/

void NVIC_EnableInterrupt(uint8  InterruptID)
{ 
   if (InterruptID <= 31)
     {
		SET_BIT(NVIC_EN0, InterruptID);
	 }
  else if (InterruptID <= 63)
     {
		SET_BIT(NVIC_EN1, InterruptID - 32);
	 }
  else if (InterruptID <= 95)
     {
		SET_BIT(NVIC_EN2, InterruptID - 64);
	  }
  else if (InterruptID <= 127) 
      {
		SET_BIT(NVIC_EN3, InterruptID - 96);
	  }
  else if (InterruptID <= 138)
     {
		SET_BIT(NVIC_EN4, InterruptID - 128);
     }
  else
     {
	 /* Nothing*/
	 }
}

/******************************************************************************
* \Syntax          : void NVIC_DisableInterrupt(uint8 InterruptID) 
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : InterruptID
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void NVIC_DisableInterrupt(uint8 InterruptID) 
{

   if (InterruptID <= 31)
     {
		SET_BIT(NVIC_DIS0, InterruptID);
	 }
  else if (InterruptID <= 63)
     {
		SET_BIT(NVIC_DIS1, InterruptID - 32);
	 }
  else if (InterruptID <= 95)
     {
		SET_BIT(NVIC_DIS2, InterruptID - 64);
	  }
  else if (InterruptID <= 127) 
      {
		SET_BIT(NVIC_DIS3, InterruptID - 96);
	  }
  else if (InterruptID <= 138)
     {
		SET_BIT(NVIC_DIS4, InterruptID - 128);
     }
  else
     {
	 /* Nothing*/
	 }
}

/**********************************************************************************************************************
 *  END OF FILE: Interrupt.c
 *********************************************************************************************************************/