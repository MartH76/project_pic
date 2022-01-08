/* 
 * File:   main.c
 * Author: huvelin husser
 *
 * Created on 15 novembre 2021, 14:40
 */

#include "def.h"
//#include "uart.h"

/*
unsigned char j;

int main(void)
{
    j=0; //variable a 0 pour clignoter la led
    TRISDbits.RD0 = 0; //Pin TRISD0 mis en sortie
    TRISDbits.RD1 = 0;
    TRISDbits.RD2 = 0;
    TRISDbits.RD3 = 0;
    while(1){
        j=!j; //on change la variable
        PORTDbits.RD0 = j; //on change l'état du pin RD0 low ou high
        __delay_ms(70);
        PORTDbits.RD1 = j;
        __delay_ms(70);
        PORTDbits.RD2 = j;
        __delay_ms(70);
        PORTDbits.RD3 = j;
        __delay_ms(70); // on attend 70ms
    }    
}
int main(void)
{
    TRISDbits.TRISD0 = 0; //Pin TRISD0 mis en sortie
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    PORTD = 0b00000001;
    while(1){
        int i = 0;
        unsigned char j = 0b00000001;
        while (i <= 3){
            PORTD = j; 
            __delay_ms(70);
            j = j << 1; //shift gauche de 1bit
            i = i + 1;
            // on attend 70ms
        } 
    }    
}

int main(void)
{
    TRISDbits.RD0 = 0; //Pin TRISD0 mis en sortie
    PORTDbits.RD0 = 0;
    init_timer();
    TMR0L = 0;
    unsigned char i;
    i=0;
    while(1){
        
        if (TMR0L > 254){
            i = !i;
            TMR0L = 0;
        } 
        PORTDbits.RD0 = i; 
    }   
}



int main(void)
{
    TRISDbits.RD0 = 0; //Pin TRISD0 mis en sortie
    PORTDbits.RD0 = 0;
    init_timer();
    TMR0L = 0;
    
    while(1){
        PORTDbits.RD0 = i;
    }   
}

 Code pour chenillard
int main(void)
{
    TRISD = 0b00000000; //Pin TRISD0 mis en sortie
    PORTDbits.RD0 = 0;
    PORTDbits.RD1 = 0;
    PORTDbits.RD2 = 0;
    PORTDbits.RD3 = 0;
    
    init_timer();
    TMR0L = 0;
    j = 0b00000001;
    while(1){
        PORTD = j;
    }   
}
int main(void)
{
    unsigned char a = 0b01010111;
    unsigned char b;
    
    TRISD = 0b00000000;
    TRISB = 0b00000000;
    init_uart(); 
    while(1){
        write_uart(a);
        b = read_uart();
        PORTD = b;
        __delay_ms(50);
    }
}

int main(void){
    __delay_ms(20);
    init_uart();
    init_timer();
    unsigned char a = 0;
    TRISDbits.RD0 = 0;
    while (a == 0){
         init_rfid();
         a = echo();            
    }    
    while(1){
    PORTDbits.RD0 = 0;
    __delay_ms(50);
    PORTDbits.RD0 = 1;
    __delay_ms(50);
    }
}*/

/*
int main(void){
    __delay_ms(20);
    init_rfid();
    init_uart();
    init_timer();
    unsigned char titi ;
    titi=0;
    
    TRISDbits.RD0 = 0;
    while (titi==0){
         titi = echo(); 
    }  
    INTCONbits.TMR0IE = 0; //enable overflow interupt
    T0CONbits.TMR0ON = 0;//enable timer0
    INTCONbits.GIE = 0; //enable all interrupt
   
    identite();
    unsigned char attention = 0;
    char rep[16]={0x4E,0x46,0x43,0x20,0x46,0x53,0x32,0x4A,0x41,0x53,0x54,0x32,0x00};
    for (i=0;i<(longueur-2);i++){
            if (rep[i]!=tab[i]){
                attention = 1;
            }
    }
    
    calibration();
    select_protocol();
    if (protocol_test[0] != 0x00 || protocol_test[1] != 0x00){
        attention = 1;
    }
    __delay_ms(50);
    if (attention == 0){ 
        get_NFC_tag();
        while (!verification_id()){
            get_NFC_tag();
        }
        while(1){
            PORTDbits.RD0 = 0;
            ouverture();

            PORTDbits.RD0 = 1;
            fermeture();
            }
    }
    while(1);
}
*/

int main (void){
    TRISBbits.RB2 = 1;
    TRISDbits.RD1 = 0;
    PORTDbits.RD1 = 0;
    TRISDbits.RD2 = 0;
    PORTDbits.RD2 = 0;
    init_timer_v2();
    init_port();
    partie();
    while(1){
        if (compteur == 0){
            PORTDbits.RD1 = 1;
        }
        else{
            PORTDbits.RD2 = 1;
        }
    }
}