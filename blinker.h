/*
 * File:   blinker.h
 * Author: root
 *
 * Created on November 15, 2013, 11:04 AM
 */

#ifndef BLINKER_H
#define	BLINKER_H

#include "pat.h"

void Blink_Init(void);
uint8_t blink_led(uint8_t, uint8_t, uint8_t);
uint8_t blink_led_alt(uint8_t);
uint8_t is_led_blinking(uint8_t);
uint8_t is_led_on(uint8_t);

#ifdef	__cplusplus
extern "C" {
#endif

	extern volatile struct V_data V;
	extern volatile union Obits2 LEDS;

#ifdef	__cplusplus
}
#endif

#endif	/* BLINKER_H */
