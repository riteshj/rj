/* 
 * File:   main.h
 * Author: rj
 *
 * Created on 20 September, 2014, 7:43 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

void PIC_ADC_INIT(void);
void SYS_INIT(void);

#define ANALOG          1
#define DIGITAL         0

#define RIGHT_JUSTIFIED 1
#define LEFT_JUSTIFIED  0

#define VREF_PIN        1
#define VDD             0

#define START_ADC       1
#define ADC_RDY        0

#define CH_0            0
#define CH_1            1
#define CH_2            2
#define CH_3            3
#define CH_4            4
#define CH_5            5
#define CH_6            6
#define CH_7            7



#define ENABLE_ADC      1
#define DISABLE_ADC     0

#define START_ADC       1
#define POLL_ADC        2
#define READ_ADC        3
#define LED_OUTPUT      4
#define TIME_OUT        5


#define TIME_TICKS      0xfffe
#define THRESHOLD       500


#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

