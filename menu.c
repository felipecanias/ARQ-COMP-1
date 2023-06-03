#include <ncurses.h>
#include "leds.c"

void menu() {
    int opcion;
    int delays[] = {10000, 10000, 10000, 10000, 10000};

    while (1) {
        printw("---Menu---\n");
        printw("1) Auto Fantastico\n");
        printw("2) El Choque\n");
        printw("3) La Carrera\n");
        printw("4) Caso 4\n");
        printw("5) Caso 5\n");
        printw("6) Exit\n\n");

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
                printw("\nMenu 4\n");
                break;
            case 5:
                printw("\nMenu 4\n");
                break;
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
