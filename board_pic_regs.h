#ifndef __BOARD_PIC_REGS_H_
#define __BOARD_PIC_REGS_H_

/* Application registers */
#define BOARD_PIC_REG_IMU_CTRL              0x00
#define BOARD_PIC_REG_ENV_SENSOR_CTRL       0x01
#define BOARD_PIC_REG_MIC_CTRL              0x02
#define BOARD_PIC_REG_CCS_CTRL              0x03
#define BOARD_PIC_REG_LED_CTRL              0x04
#define BOARD_PIC_REG_INT_ENABLE            0x05
#define BOARD_PIC_REG_INT_CLEAR             0x06
#define BOARD_PIC_REG_INT_FLAG              0x07
#define BOARD_PIC_REG_INT_CTRL              0x08

#define BOARD_PIC_NUM_APP_REGS              9

/* System registers */
#define BOARD_PIC_REG_SYS_CMD               0xF0
#define BOARD_PIC_REG_VERSION_MAJOR         0xF1
#define BOARD_PIC_REG_VERSION_MINOR         0xF2
#define BOARD_PIC_REG_VERSION_PATCH         0xF3

#define BOARD_PIC_REG_SCRATCH0              0xF4
#define BOARD_PIC_REG_SCRATCH1              0xF5
#define BOARD_PIC_REG_SCRATCH2              0xF6
#define BOARD_PIC_REG_SCRATCH3              0xF7

#define BOARD_PIC_REG_DEVICE_ID0            0xF8
#define BOARD_PIC_REG_DEVICE_ID1            0xF9
#define BOARD_PIC_REG_DEVICE_ID2            0xFA
#define BOARD_PIC_REG_DEVICE_ID3            0xFB

#define BOARD_PIC_REG_BOARD_REV             0xFC

#define BOARD_PIC_SYS_REG_START             0xF0
#define BOARD_PIC_NUM_SYS_REGS              13


/* Bit fields for PIC_REG_IMU_CTRL */
#define BOARD_PIC_REG_IMU_CTRL_EN           0x01

/* Bit fields for PIC_REG_ENV_SENSOR_CTRL */
#define BOARD_PIC_REG_ENV_SENSOR_CTRL_EN    0x01

/* Bit fields for PIC_REG_MIC_CTRL */
#define BOARD_PIC_REG_MIC_CTRL_EN           0x01

/* Bit fields for PIC_REG_CCS_CTRL */
#define BOARD_PIC_REG_CCS_CTRL_EN           0x01
#define BOARD_PIC_REG_CCS_CTRL_WAKE         0x02

/* Bit fields for PIC_REG_LED_CTRL */
#define BOARD_PIC_REG_LED_CTRL_PWR_EN       0x01
#define BOARD_PIC_REG_LED_CTRL_LED0         0x10
#define BOARD_PIC_REG_LED_CTRL_LED1         0x20
#define BOARD_PIC_REG_LED_CTRL_LED2         0x40
#define BOARD_PIC_REG_LED_CTRL_LED3         0x80
#define BOARD_PIC_REG_LED_CTRL_LED_MASK     0xf0
#define BOARD_PIC_REG_LED_CTRL_LED_SHIFT    4

/* Bit fields for PIC_REG_INT_ENABLE */
#define BOARD_PIC_REG_INT_ENABLE_CCS811     0x01
#define BOARD_PIC_REG_INT_ENABLE_IMU        0x02
#define BOARD_PIC_REG_INT_ENABLE_UV_ALS     0x04

/* Bit fields for PIC_REG_INT_FLAG */
#define BOARD_PIC_REG_INT_FLAG_CCS811       0x01
#define BOARD_PIC_REG_INT_FLAG_IMU          0x02
#define BOARD_PIC_REG_INT_FLAG_UV_ALS       0x04

/* Bit fields for PIC_REG_INT_CLEAR */
#define BOARD_PIC_REG_INT_CLEAR_CCS811      0x01
#define BOARD_PIC_REG_INT_CLEAR_IMU         0x02
#define BOARD_PIC_REG_INT_CLEAR_UV_ALS      0x04

/* Bit fields for PIC_REG_INT_CTRL */
#define BOARD_PIC_REG_INT_CTRL_TIMER_MASK   0x0F
#define BOARD_PIC_REG_INT_CTRL_TIMER_SHIFT  0
#define BOARD_PIC_REG_INT_CTRL_TIMER_ENABLE 0x10
#define BOARD_PIC_REG_INT_CTRL_LEGACY_MODE  0x20

#define BOARD_PIC_REG_SYS_CMD_BOOTMODE      0xA5

#endif
