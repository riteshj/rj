/* 
 * File:   pic_main.c
 * Author: rj
 *
 * Created on 17 September, 2014, 4:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic16f688.h>
#include "main.h"
/*
 * 
 */
int main(int argc, char** argv) {

unsigned char adc_state = 1 ;
unsigned int time_out = 0 ;
unsigned int adcval = 0;

SYS_INIT();
PIC_ADC_INIT();

while(1){

 switch(adc_state)
 {
     case START_ADC :
                     ADCON0bits.GO = START_ADC ;
                     adc_state = POLL_ADC ;
                     break ;

     case POLL_ADC :
                    if(ADCON0bits.GO == ADC_RDY)
                    {
                      adc_state = READ_ADC ;
                      time_out = 0;
                    }
                    else
                    {
                      time_out++ ;
                      if(time_out > TIME_TICKS )
                       adc_state = TIME_OUT ;
                    }
                    break ;

     case READ_ADC :
                    adcval = ((ADRESH << 8) | ADRESL) ;

                    if(adcval > THRESHOLD)   //light decrease count increase
                     PORTCbits.RC0 = 1; //RC0 is high level
                    else
                     PORTCbits.RC0 = 0; //RC0 is low level

                    adc_state = START_ADC ;
                    break ;
     case TIME_OUT :
                     PIC_ADC_INIT();
                     adc_state = START_ADC ;
                     time_out = 0;
                     break ;
 }

}
   return (EXIT_SUCCESS);
}

void SYS_INIT(void){

OSCCONbits.IRCF0 = 1;   // 8MHZ internal oscillator
OSCCONbits.IRCF1 = 1;
OSCCONbits.IRCF2 = 1;
OSCCONbits.HTS   = 1;
OSCCONbits.LTS   = 0;
OSCCONbits.SCS   = 1;   // select internal oscillator

}

void PIC_ADC_INIT(void){
    
TRISAbits.TRISA2 = 0     ;     // configure port0 pin 2 as output
ANSELbits.ANS3  = ANALOG ;     // configure port0 pin 3 as analog input

ADCON0bits.ADFM = RIGHT_JUSTIFIED ;
ADCON0bits.VCFG = VDD  ;
ADCON0bits.CHS  = CH_7 ;

ADCON1bits.ADCS = 5    ;        //FOSC/16  sampling 

ADCON0bits.ADON = ENABLE_ADC ;


}









