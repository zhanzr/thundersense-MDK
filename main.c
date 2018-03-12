#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"

#include "retargetserial.h"

#include "bspconfig.h"

#include "board.h"
#include "util.h"

int main(void)
{
  uint8_t ledMask;

  EMU_DCDCInit_TypeDef dcdcInit = EMU_DCDCINIT_TBSENSE_DEFAULT;
  CMU_HFXOInit_TypeDef hfxoInit = CMU_HFXOINIT_TBSENSE_DEFAULT;

  /* Chip errata */
  CHIP_Init();

  /* Init DCDC regulator and HFXO with WSTK radio board specific parameters
     from bspconfig.h */
  EMU_DCDCInit(&dcdcInit);
  CMU_HFXOInit(&hfxoInit);

  /* Switch HFCLK to HFXO and disable HFRCO */
  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);
  CMU_OscillatorEnable(cmuOsc_HFRCO, false, false);

/* Initialize LEUART/USART and map LF to CRLF */
	RETARGET_SerialInit();
	RETARGET_SerialCrLf(1);
	
  /* Setup SysTick Timer for 1 msec interrupts  */
  UTIL_init();
  BOARD_init(); 

  ledMask = 1;
  BOARD_ledSet(ledMask);

	printf("VCOM of EFR32MG1P132 %u Hz\n", SystemCoreClock);
	
  /* Infinite blink loop */
  while (1)
  {
    ledMask ^= 0x3;
    BOARD_ledSet(ledMask);
    UTIL_delay(1000);
  }
}
