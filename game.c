#include "def.h"

//definition de btn
#define SWITCH_1 PORTBbits.RB6
#define SWITCH_2 PORTBbits.RB7

char SW1_time = 0;
char SW2_time = 0;

char old_SW1_time = 0;
char old_SW2_time = 0;

int SW1_state = 0;
int SW2_state = 0;

int old_SW1_state = 0;
int old_SW2_state = 0;

int i1 = 0;
int i2 = 0;

//int compteur = 10; //compteur=0 joureur 1 gagne compteur=20 joureur 2 gagne


int delay_debounce = 10; //a modifier


void init_port(){
    TRISBbits.TRISB6 = 1; //entrée pour les switchs
    TRISBbits.TRISB7 = 1;
}


void partie(){
    millis = 0;
    while (en_cours == 1){
        old_SW1_state = SW1_state;
        old_SW2_state = SW2_state;
        
        SW1_state = PORTBbits.RB6;
        SW2_state = PORTBbits.RB7;
        
        if (SW1_state != old_SW1_state){
            old_SW1_time = SW1_time;
            SW1_time = millis;
            if (SW1_time - old_SW1_time < delay_debounce){
                 SW1_state = !SW1_state;
            }else{
                if (SW1_state == 1){
                    compteur = compteur-1;
                }
            }
        }
        if (SW2_state != old_SW2_state){
            old_SW2_time = SW2_time;
            SW2_time = millis;
            if (SW2_time - old_SW2_time < delay_debounce){
                SW2_state = !SW2_state;
            }else{
             if (SW2_state ==1){
                compteur = compteur+1;
             }
            }
        }
        if (compteur==0 || compteur==20){
            en_cours = 0;
        }
    }   
}