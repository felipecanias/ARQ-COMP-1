#include <ncurses.h>
#include "leds.c"

void menu() {
    int opcion;

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
                auto_fantastico();
                break;
            case 2:
                printw("\nMenu 2\n");
                break;
            case 3:
                printw("\nMenu 3\n");
                break;
            case 4:
                printw("\nMenu 4\n");
                break;
            case 5:
                printw("\nExit\n");
                return;
            default:
                printw("\nOpción inválida\n");
                break;
        }
        clear();
    }
}
