#include <ncurses.h>
#include "leds.c"
//#include "EasyPIO.h"

extern void otro_asm();
extern void parpadeo_estelar_asm();

void menu() {
//    pioInit();
//    char led[] = {14, 15, 18, 23, 24, 25, 8,7};
//    for (int i=0; i<=7;i++){
//        pinMode(led[i],OUTPUT);
//    }

    int opcion;
    int delays[] = {50, 50, 50, 50, 50};
    while (1) {
//        uint8_t output = 0x00;
//        outportb (output);

        printw("---Menu---\n");
        printw("1) Auto Fantastico\n");
        printw("2) El Choque\n");
        printw("3) La Carrera\n");
        printw("4) Parpadeo Estelar\n");
        printw("5) Ella se fue con otro :(\n");
//        printw("6) Fuegos Artificiales\n");
        init_pair(2, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        printw("6) Exit\n\n");
        attroff(COLOR_PAIR(2));

        printw("Seleccione una opción: ");
        opcion = getch() - '0';
        clear();

        switch (opcion) {

            case 1:
                auto_fantastico(&delays[0]);
                break;

            case 2:
                choque(&delays[1]);
                break;

            case 3:
                carrera(&delays[2]);
                break;
            case 4:
                parpadeo_estelar_asm(&delays[3]);
                break;
            case 5:
                otro_asm(&delays[4]);
                break;
//            case 6:
//                fuegos_artificiales(&delays[5]);
//                break;
            case 6:
                printw("\nExit\n");
                return;
            default:
                printw("\nOpción inválida\n");
                break;
        }
        clear();
    }
}

/*
loop2:
    MOV R4, #0x01
    MOV R5, #1

    CMP R5, #0
    BEQ display_none
    BNE display
    LSLNE R4, R4, #1

    CMP R4, #0
    BEQ loop

    MOV R0, R6
    BL delay
    CMP R0, #0
    POPEQ {R4, R5, R6, R7, PC}

    B loop2
 */

/*

.text

.global parpadeo_estelar_asm

display:
    MOV R0, R4
    LDR R1, =name
    MOV R2, R6
    BL disp_binary

display_none:
    MOV R0, #0
    LDR R1, =name
    MOV R2, R6
    BL disp_binary


parpadeo_estelar_asm:
      PUSH {R4, R5, R6, LR}     //Guardo en pila por ser subrutina
      MOV R6, R0                //Guardo el delay en R6

loop:
    MOV R4, #0x80
    MOV R5, #1

    CMP R5, #0
    BEQ display_none
    MOVEQ R5, #1
    BNE display
    MOVNE R5, #0
    LSRNE R4, R4, #1

    MOV R0, R6
    BL delay
    CMP R0, #0
    POPEQ {R4, R5, R6, PC}

    B loop


.data
name:
	.asciz "Parpadeo Estelar2"

.end


 */
