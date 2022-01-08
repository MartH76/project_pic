
#include "def.h"

void init_rfid(){
    //On utilise notre liaison uart pour init le rfid 1bit  à notre baud rate equivaut à 100us
    //on reste à 0 pendant 700us puis on passe à 1 pendant 200us 
    //si on avait init en utilisant trisc il aurait fallut init lme rfid avant l'uart.
    //write_uart(0b10000000);
    
    RCSTA1bits.SPEN = 0;
    TXSTA1bits.TXEN = 0;
    TRISCbits.TRISC6 = 0;
    PORTCbits.RC6 = 1;
    __delay_us(200);
    PORTCbits.RC6 = 0;
    __delay_us(100);
     PORTCbits.RC6 = 1;
    __delay_us(200);
}

char echo(){
   char toto;
   flag = 0;
   write_echo();
   toto=read_echo();
   if(toto == 0x55){
       return 1;
   }
   else
   return 0;     
}

char read_echo(){
    while(!PIR1bits.RC1IF && !flag); // flag passe a 1 quand le timer dépasse la valeur voulue
    if(flag == 1){
       flag=0;
       return 0x0f;
    }
    else
    return RCREG1;
}

void write_echo(){
    write_uart(0x55);
}

void identite(){
    write_uart(0x01);
    write_uart(0x00);
    longueur = read_uart(); //poubelle du 0x00
    longueur = read_uart();
    for(i=0;i<longueur;i++){
        tab[i]=read_uart();        
    }
}


void calibration(){
    char calibration[16] = {0x07,0x0E,0x03,0xA1,0x00,0xF8,0x01,0x18,0x00,0x20,0x60,0x60,0x00,0x00,0x3F,0x01}; 
    char calibration_char_13[8] = {0x00, 0xFC, 0x7C, 0x3C, 0x5C, 0x6C, 0x74, 0x70};  
    char buffer = 0;
    for (int p=0;p<8;p++){ 
        calibration[13] = calibration_char_13[p];
        for (int m = 0; m<16; m++){
            write_uart(calibration[m]);
        }
        calibtest[p][0] = read_uart();
        calibtest[p][1] = read_uart();
        calibtest[p][2] = read_uart();
        if (calibtest[p][2]==0x02){
            buffer = p;
        }
    }
    calibration[13] = calibration_char_13[buffer];
    for (int m = 0; m<16; m++){
            write_uart(calibration[m]);
        }
    calibtest[buffer][0] = read_uart(); //vider l'uart
    calibtest[buffer][1] = read_uart();
    calibtest[buffer][2] = read_uart();
}

void select_protocol(){
    char protocol[4] = {0x02, 0x02, 0x02, 0x00}; // SO/IEC 14443 Type A tag, 106 Kbps transmission and reception 
    for (int q = 0; q < 4;q++){
        write_uart(protocol[q]);
    }
    protocol_test[0] = read_uart();
    protocol_test[1] = read_uart();
}

void get_NFC_tag(){
    char cmd_1[4] = {0x04, 0x02, 0x26, 0x07};     //activation command
    char cmd_2[5] = {0x04, 0x03, 0x93, 0x20, 0x08};  //(Anti-collision CL1)
    char poubelle; 
    //etape 1
    for(int a=0;a<4;a++){
        write_uart(cmd_1[a]);
    }
    poubelle = read_uart();
    longueur = read_uart();
    for(int a=0;a<longueur;a++){
        resultat_1[a] = read_uart();
    }
    //etape 2
    for(int a=0;a<5;a++){
        write_uart(cmd_2[a]);
    }
    poubelle = read_uart();
    longueur = read_uart();
    for(int a=0;a<longueur;a++){
        resultat_2[a] = read_uart();
    }
    for(int a=(longueur-8);a<longueur;a++){
        tag_id[a] = resultat_2[a];
    }
}


void ouverture()
{   
    TRISBbits.TRISB0 = 0;
    for(int i=0; i< 100; i++){
    PORTBbits.RB0 = 1;
    __delay_ms(1);
    PORTBbits.RB0 = 0;
    __delay_ms(19);
    }
}
void fermeture()
{
    TRISBbits.TRISB0 = 0;
    for(int i=0; i< 100; i++){
    PORTBbits.RB0 = 1;
    __delay_ms(2);
    PORTBbits.RB0 = 0;
    __delay_ms(18);
    }

}


char verification_id(){
    for(int k=0;k<8;k++){
        if (tag_id[k]!=tag_id1[k]){
            return 0;
        }
    }
    return 1;
}