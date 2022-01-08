#include <p18f45K22.h>
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 8000000 // On définit la valeur d'une variable globale à _XTAL_FREQ à 10000000

#pragma config FOSC = HSMP
#pragma config FCMEN = OFF
#pragma config WDTEN = OFF
#pragma config XINST = OFF

#pragma config LVP = OFF

long millis = 0;

unsigned char i;
unsigned char j;
unsigned char flag;

char tab[20]={0};
char calibtest[8][3] = {0};
char protocol_test[2] = {0};
char longueur;

// utilise dans get_NFC_tag
char resultat_1[30];
char resultat_2[30];
char tag_id[8] = {0};
char tag_id1[8] = {0xa7, 0xc6, 0xd9, 0xc5, 0x7d, 0x28, 0x00, 0x00};
void init_timer();

void interrupt isr();

void Adc_init(void);
float conv();
void init_led(void);

void init_uart();
void write_uart (unsigned char);
char read_uart ();


void init_rfid();

char echo();
void write_echo();
char read_echo();

void identite();
void calibration();
void select_protocol();

void get_NFC_tag();

void ouverture();
void fermeture();

char verification_id();

void partie();
void antibounce();
void init_port();
void init_timer_v2();

int compteur = 10; //compteur=0 joureur 1 gagne compteur=20 joureur 2 gagne

char en_cours = 1;