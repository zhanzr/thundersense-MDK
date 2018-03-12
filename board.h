/***************************************************************************//**
 *
 * @file board.h
 * @brief BOARD module header file
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
 ******************************************************************************
 */

#ifndef __BOARD_H_
#define __BOARD_H_

/***************************************************************************//**
 * @addtogroup BOARD
 * @{
 ******************************************************************************/

#include <stdint.h>

#include "em_gpio.h"

#include "i2cspm.h"

#include "board_pic_regs.h"
#include "board_rgbled_profiles.h"

/***************************************************************************//**
 * @defgroup BOARD_Error_Messages BOARD module error codes
 * @{
 * @brief BOARD module error return codes macro definitions
 ******************************************************************************/
#define BOARD_OK                              0     /**< OK                           */
#define BOARD_ERROR_I2C_TRANSFER_TIMEOUT      0x01  /**< I2C timeout occurred         */
#define BOARD_ERROR_I2C_TRANSFER_NACK         0x02  /**< No acknowledgement received  */
#define BOARD_ERROR_I2C_TRANSFER_FAILED       0x03  /**< I2C transaction failed       */
#define BOARD_ERROR_PIC_ID_MISMATCH           0x04  /**< The ID of the PIC is invalid */
#define BOARD_ERROR_PIC_FW_INVALID            0x05  /**< Invalid PIC firmware         */
#define BOARD_ERROR_PIC_FW_UPDATE_FAILED      0x06  /**< PIC firmware update failed   */
/** @} */

/***************************************************************************//**
 * @defgroup BOARD_Config_Settings BOARD module configuration
 * @{
 * @brief BOARD module configuration macro definitions
 ******************************************************************************/

#define BOARD_PIC_DEVICE_ID       0x50584F49      /**< PIC device ID                    */
#define BOARD_PIC_INT_WAKE_PORT   gpioPortD       /**< PIC INT/Wakeup port              */
#define BOARD_PIC_INT_WAKE_PIN    10              /**< PIC INT/Wakeup pin               */

#define BOARD_RGBLED_TIMER        (TIMER0)        /**< RGB LED PWM control timer        */
#define BOARD_RGBLED_CMU_CLK      cmuClock_TIMER0 /**< RGB LED PWM control clock source */
#define BOARD_RGBLED_RED_PORT     gpioPortD       /**< RGB LED Red port                 */
#define BOARD_RGBLED_RED_PIN      11              /**< RGB LED Red pin                  */
#define BOARD_RGBLED_RED_CCLOC    19              /**< RGB LED Red CC location          */
#define BOARD_RGBLED_GREEN_PORT   gpioPortD       /**< RGB LED Green port               */
#define BOARD_RGBLED_GREEN_PIN    12              /**< RGB LED Green pin                */
#define BOARD_RGBLED_GREEN_CCLOC  19              /**< RGB LED Green CC location        */
#define BOARD_RGBLED_BLUE_PORT    gpioPortD       /**< RGB LED Blue port                */
#define BOARD_RGBLED_BLUE_PIN     13              /**< RGB LED Blue pin                 */
#define BOARD_RGBLED_BLUE_CCLOC   19              /**< RGB LED Blue CC location         */

#define BOARD_BUTTON_PORT         gpioPortD       /**< Pushbutton port                  */
#define BOARD_BUTTON_SHIFT        14              /**< Pushbutton shift value           */
#define BOARD_BUTTON_LEFT         0x01            /**< Left pushbutton value            */
#define BOARD_BUTTON_RIGHT        0x02            /**< Right pushbutton value           */
#define BOARD_BUTTON_MASK         0x03            /**< Pushbutton mask                  */
#define BOARD_BUTTON_LEFT_PORT    gpioPortD       /**< Left pushbutton port             */
#define BOARD_BUTTON_LEFT_PIN     14              /**< Left pushbutton pin              */
#define BOARD_BUTTON_RIGHT_PORT   gpioPortD       /**< Right pushbutton port            */
#define BOARD_BUTTON_RIGHT_PIN    15              /**< Right pushbutton pin             */
#define BOARD_BUTTON_INT_FLAG     0x04            /**< Pushbutton interrupt flag value  */
#define BOARD_BUTTON_INT_ENABLE   true            /**< Pushbutton interrupt enable      */

#define BOARD_FLASH_USART         (USART1)        /**< NOR Flash USART                  */
#define BOARD_FLASH_PORT_SPI      gpioPortC       /**< NOR Flash SPI bus GPIO port      */
#define BOARD_FLASH_PORT_SPI_CS   gpioPortA       /**< NOR Flash SPI bus CS GPIO port   */
#define BOARD_FLASH_PIN_SPI_MOSI  6               /**< NOR Flash MOSI GPIO pin          */
#define BOARD_FLASH_PIN_SPI_MISO  7               /**< NOR Flash MISO GPIO pin          */
#define BOARD_FLASH_PIN_SPI_CLK   8               /**< NOR Flash CLK GPIO pin           */
#define BOARD_FLASH_PIN_SPI_CS    4               /**< NOR Flash CS GPIO pin            */

/** @} */

/** @} */

/***************************************************************************//**
 * @addtogroup BOARD_Functions
 * @{
 ******************************************************************************/
uint32_t BOARD_init                ( void );

uint32_t BOARD_imuEnable           ( bool enable );
uint32_t BOARD_imuEnableIRQ        ( bool enable );

uint32_t BOARD_envSensEnable       ( bool enable );
uint32_t BOARD_envSensEnableIRQ    ( bool enable );

void     BOARD_flashDeepPowerDown  ( void );

uint32_t BOARD_gasSensorEnable     ( bool enable );
uint32_t BOARD_gasSensorEnableIRQ  ( bool enable );
uint32_t BOARD_gasSensorWake       ( bool wake );

void     BOARD_ledSet              ( uint8_t leds );

uint32_t BOARD_micEnable           ( bool enable );

uint32_t BOARD_picIntGet           ( uint8_t *flags );
uint32_t BOARD_picIntClear         ( uint8_t flags );
uint32_t BOARD_picWriteReg         ( uint8_t addr, uint8_t value );
uint32_t BOARD_picReadReg          ( uint8_t addr, uint8_t *result );
uint32_t BOARD_picRegBitsSet       ( uint8_t addr, bool set, uint8_t bitMask );
uint32_t BOARD_picGetDeviceId      ( void );
uint32_t BOARD_picGetFwRevision    ( uint8_t *major, uint8_t *minor, uint8_t *patch );
uint8_t  BOARD_picGetHwRevision    ( void );
bool     BOARD_picIsLegacyIntCtrl  ( void );

uint8_t  BOARD_pushButtonGetState  ( void );
void     BOARD_pushButtonEnableIRQ ( bool enable );

void     BOARD_rgbledEnable        ( bool enable, uint8_t mask );
void     BOARD_rgbledSetColor      ( uint8_t red, uint8_t green, uint8_t blue );
void     BOARD_rgbledSetRawColor   ( uint16_t red, uint16_t green, uint16_t blue );
void     BOARD_rgbledPowerEnable   ( bool enable );

/** @} */

/***************************************************************************//**
 * @}                                                                          *
 ******************************************************************************/
#endif
