/***************************************************************************//**
 *
 * @file util.c
 * @brief Utility Functions for the Thunderboard Sense
 *
 *******************************************************************************
 *
 * @section License
 *
 *  Copyright (C) 2016-2017 Silicon Labs, http://www.silabs.com
 *
 *  SPDX-License-Identifier: Apache-2.0
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#include "board.h"
#include "util.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"

/***************************************************************************//**
 * @defgroup Util Utility Functions
 * @{
 * @brief Utility functions
 ******************************************************************************/

/***************************************************************************//**
 * @defgroup Util_Locals Utility Functions Local Variables
 * @{
 * @brief Local variables used in the utility functions
 ******************************************************************************/
/* Local variables */
volatile uint32_t msTickCount;       /**< Counts 1ms time ticks               */
/** @} */

/***************************************************************************//**
 * @defgroup Util_Functions Utility Functions
 * @{
 * @brief Utility functions
 ******************************************************************************/

/***************************************************************************//**
 * @brief
 *    Sets up the SysTick timer for 1ms interrupts and initializes and starts
 *    the RTC timer
 *
 * @return
 *    Returns zero on OK, non-zero otherwise
 ******************************************************************************/
uint32_t UTIL_init( void )
{

   uint32_t stat;
   uint32_t ticks;

   /* Setup SysTick Timer for 1 msec interrupts  */
   ticks = CMU_ClockFreqGet( cmuClock_CORE ) / 1000;
   stat = SysTick_Config( ticks );

   return stat;

}

/***************************************************************************//**
 * @brief
 *    Interrupt Service Routine for system tick counter
 *
 * @return
 *    None
 ******************************************************************************/
void SysTick_Handler( void )
{

   msTickCount++;

   return;

}

/***************************************************************************//**
 * @brief
 *    Delays number of msTick Systicks (1 ms)
 *
 * @param[in] ms
 *    Number of ticks (ms) to delay
 *
 * @return
 *    None
 ******************************************************************************/
void UTIL_delay( uint32_t ms )
{

   uint32_t curTicks;

   curTicks = msTickCount;
   while( ( msTickCount - curTicks ) < ms ) {
      EMU_EnterEM1();
   }

   return;

}

/***************************************************************************//**
 * @brief
 *    Enter lowest power shutdown mode, EM4S
 *
 * @return
 *    None
 ******************************************************************************/
void UTIL_shutdown( void )
{

   EMU_EM4Init_TypeDef em4Init = EMU_EM4INIT_DEFAULT;

   em4Init.pinRetentionMode = emuPinRetentionEm4Exit;
   EMU_EM4Init( &em4Init );

   /* Set up for EM4 wakeup from gpio PD14 (EM4WU4). Need to enable glitch filter */
   GPIO_PinModeSet( BOARD_BUTTON_PORT, BOARD_BUTTON_LEFT_PIN, gpioModeInputPullFilter, 1 );
   GPIO_EM4EnablePinWakeup( ( 0x10 << _GPIO_EM4WUEN_EM4WUEN_SHIFT ), 0 );

   EMU_EnterEM4();

   return;

}

/** @} */

/***************************************************************************//**
 * @}                                                                          *
 ******************************************************************************/
