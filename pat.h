#ifndef PAT_H_INCLUDED
#define PAT_H_INCLUDED
//	hardware defines

#ifdef INTTYPES
#include <stdint.h>
#else
#define INTTYPES
/*unsigned types*/
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
/*signed types*/
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed long int32_t;
typedef signed long long int64_t;
#endif

typedef struct V_data { // ISR data structure
	uint16_t blink, blink_out, blink_alt, spin_count0, spin_count1, sample_freq, max_freq,
	spurious_int;
	uint8_t valid : 1;
	uint8_t comm : 1;
	uint8_t comm_state, sleep_ticks;
	uint8_t spinning : 1;
	uint8_t boot_code : 1;
	uint8_t mod_count, rx_data, tx_data;
	uint8_t led_pwm[8],led_pwm_set[8];
} V_data;

typedef struct OUTBITS2 {
	uint8_t b0 : 1;
	uint8_t b1 : 1;
	uint8_t b2 : 1;
	uint8_t b3 : 1;
	uint8_t b4 : 1;
	uint8_t b5 : 1;
	uint8_t b6 : 1;
	uint8_t b7 : 1;
} OUTBITS_TYPE2;

union Obits2 {
	uint8_t out_byte;
	OUTBITS_TYPE2 out_bits;
};

#define TRUE	1
#define FALSE	0
#define	ON	1
#define	OFF	0
#define	LEDON	0   // logic low lights led
#define	LEDOFF	1

#define	TIMEROFFSET	44268		// timer0 16bit counter value for ~1 second to overflow 44268
#define	SAMPLEFREQ	65500		// timer1 3.9khz

#define FANPORTA	TRISA
#define FANPORTB	TRISB
#define FANPORT_IOA	0b00000000		// all outputs FAN signal on 
#define FANPORT_IOB	0b00010101		// Rs-232 transmit on B1, receive on B4, fan sensors on B0,B2

#define LED1		LATAbits.LATA1
#define LED2		LATAbits.LATA2
#define LED3		LATAbits.LATA3
#define LED4		LATBbits.LATB6
#define LED5		LATBbits.LATB7
#define LED6		LATAbits.LATA6		
#define COMM_ENABLE	LATBbits.LATB3

#define RPMOUT		LATAbits.LATA0
#define TACHIN		LATBbits.LATB0
#define RPMLED		LATBbits.LATB5

#define RPM_COUNT	45
#define SLEEP_COUNT	30
#define STOP_RAMP	1
#define START_RAMP	1
#define MAX_TICK	3
#define MAX_SPURIOUS	10
#define SPIN_LIMIT_H	120

#endif 