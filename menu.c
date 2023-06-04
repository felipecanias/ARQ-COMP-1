#include <ncurses.h>
#include "leds.c"
#define port_out 0x208

void menu() {
    int opcion;
    int delays[] = {3000, 3000, 3000, 3000, 3000, 2000};


    while (1) {
        //output = 0x00;
        //outportb (port_out,~output);

        printw("---Menu---\n");
        printw("1) Auto Fantastico\n");
        printw("2) El Choque\n");
        printw("3) La Carrera\n");
        printw("4) Parpadeo Estelar\n");
        printw("5) Ella se fue con otro :(\n");
        printw("6) Fuegos Artificiales\n");
        init_pair(2, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(2));
        printw("7) Exit\n\n");
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
                parpadeo_estelar(&delays[3]);
                break;
            case 5:
                otro(&delays[4]);
                break;
            case 6:
                fuegos_artificiales(&delays[5]);
                break;
            case 7:
                printw("\nExit\n");
                return;
            default:
                printw("\nOpción inválida\n");
                break;
        }
        clear();
    }
}
