#include "def.h"

void init_timer(){
    T0CONbits.T0PS = 0b111;  //prescaler 1:16
    T0CONbits.PSA = 0; //enable prescaler
    T0CONbits.T0CS = 0; //internal clock
    T0CONbits.T08BIT = 1; //timer 8bit
    //INTCONbits.TMR0IE = 0; //disable overflow interrupt
    T0CONbits.TMR0ON = 1;//enable timer0
    
    //gestion interupt
    INTCONbits.TMR0IE = 1; //enable overflow interupt
    RCONbits.IPEN = 0; //disable interrupt priority
    INTCONbits.GIE = 1; //enable all interrupt
    INTCONbits.PEIE = 1; //Peripheral Interrupt Enable
}

/*
void interrupt isr(){
    
    if (INTCONbits.TMR0IF && INTCONbits.TMR0IE){
        INTCONbits.TMR0IF = 0;
        TMR0L = 0;
        i = !i;
    }
}
*/

/*
void interrupt isr(){
    
    if (INTCONbits.TMR0IF && INTCONbits.TMR0IE){
        INTCONbits.TMR0IF = 0;
        TMR0L = 0;
        j = j << 1;
        if(j == 0b00010000){
            j=0b00000001;
        }
        
    }
}*/

void interrupt isr(){
    if (INTCONbits.TMR0IF && INTCONbits.TMR0IE){
        INTCONbits.TMR0IF = 0;
        flag = 1;
        millis ++;
        if (millis == 65535){
            millis =0;
        }
        }  
    }
/*
void init_pwm(){
    CCP1CONbits.CCP1M = 0b1111; // PWM mode
    CCPTMRS0bits.C1TSEL = 0b00; //timer 2 pwm
    int Tosc = 1/_XTAL_FREQ;
    PR2 = ((PWMPeriod)/(4*TMR2Prescale*Tosc))-1; //registre a modifier pour la période du pwm
    
}

void init_timer2(){
    T2CONbits.T2OUTPS = 0bxxx;  //postscaler 
    T2CONbits.TMR2ON = 1; //enable timer
    T2CONbits.T2CKPS = 0bxx; //internal clock
}
*/


void init_timer_v2(){
    T0CONbits.T0PS = 0b000;  //prescaler 1:16
    T0CONbits.PSA = 0; //enable prescaler
    T0CONbits.T0CS = 0; //internal clock
    T0CONbits.T08BIT = 1; //timer 8bit
    //INTCONbits.TMR0IE = 0; //disable overflow interrupt
    T0CONbits.TMR0ON = 1;//enable timer0
    
    //gestion interupt
    INTCONbits.TMR0IE = 1; //enable overflow interupt
    RCONbits.IPEN = 0; //disable interrupt priority
    INTCONbits.GIE = 1; //enable all interrupt
    INTCONbits.PEIE = 1; //Peripheral Interrupt Enable
}