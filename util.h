/***************************************************************************//**
 *
 * @file util.h
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

#ifndef __UTIL_H_
#define __UTIL_H_

#include <stdint.h>
#include <stdbool.h>

/***************************************************************************//**
 * @addtogroup Util
 * @{
 ******************************************************************************/

/***************************************************************************//**
 * @defgroup Util_Defs Utility Definitions
 * @{
 * @brief Definitions used in the utility functions
 ******************************************************************************/
#define UTIL_SUPPLY_TYPE_UNKNOWN    0	/**< Unknown power supply type                */
#define UTIL_SUPPLY_TYPE_USB        1	/**< The board powered from the USB connector */
#define UTIL_SUPPLY_TYPE_AA         2	/**< The board powered from AA batteries      */
#define UTIL_SUPPLY_TYPE_AAA        3	/**< The board powered from AAA batteries     */
#define UTIL_SUPPLY_TYPE_CR2032     4	/**< The board powered from a CR2032 battery  */
/** @} */

/***************************************************************************//**
 * @addtogroup Util_Functions
 * @{
 ******************************************************************************/
uint32_t UTIL_init        ( void );
void     UTIL_delay       ( uint32_t ms );
void     UTIL_shutdown    ( void );

uint32_t UTIL_sleepInit   ( void );
void     UTIL_sleep       ( uint32_t ms );
uint32_t UTIL_waitForEvent( uint32_t timeout );

void     UTIL_supplyProbe                ( void );
void     UTIL_supplyGetCharacteristics   ( uint8_t *type, float *voltage, float *ir );
uint8_t  UTIL_supplyGetType              ( void );
bool     UTIL_isLowPower                 ( void );
/** @} */

/** @} */

#endif
