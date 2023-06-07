#include <stdio.h>
#include "EasyPIO.h"


void outportb(int data) {
    clear();
    char led[] = {14, 15, 18, 23, 24, 25, 8,7};
    int i =0;
    for (int mask = 128; mask > 0; mask = mask / 2) {
        if (data & mask) {
            digitalWrite(led[i], 1);
        } else {
            digitalWrite(led[i], 0);
        }
        i++;
    }
    refresh();
}


void disp_binary(int data, char *name, int *d) {
    clear();
    outportb(data);
    printw("Secuencia: %s\n\n", name);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    for (int mask = 128; mask > 0; mask = mask / 2) {
        if (data & mask) {
            attron(COLOR_PAIR(2));
            addch('*');
            attroff(COLOR_PAIR(2));
        } else {
            addch('_');
        }
    }
    printw("\n\nDelay: %u\n", *d);
    printw("Presione ESC o q para salir\n");
    refresh();
}

int checkKey(int *delayValue) {
    raw(); // Configurar modo raw
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE); // Activar modo no bloqueante para getch()
    int ch = getch();
    if (ch != ERR) {
        switch (ch) {
            case 27: // Escape
            case 'q':
                nodelay(stdscr, FALSE); // Restaurar modo bloqueante para getch()
                return 0; // Tecla de salida presionada
            case KEY_UP:
                *delayValue += 10; // Aumentar el retardo
                if (*delayValue>=100) *delayValue=100;
                break;
            case KEY_DOWN:
                *delayValue -= 10; // Reducir el retardo
                if (*delayValue<=0) *delayValue=10;
                break;
            default:
                break;
        }
    }
    nodelay(stdscr, FALSE); // Restaurar modo bloqueante para getch()
    return 1; // No se ha presionado la tecla de salida
}

int delay(int *d) {
    int i;
    int time = *d;
    time = time*10;
    unsigned int j;
    for (i = time; i > 0; --i){
        if (!checkKey(d)) return 0;
    }
    return 1;
}

int auto_fantastico(int *delayValue) {
    unsigned char output;
    char t;
    do {
        output = 0x80;
        for (t = 0; t < 8; t++) {
            disp_binary(output, "Auto Fantastico", delayValue);
            if (!delay(delayValue)) return 1;
            output = output >> 1;
        }
        output = 0x01;
        for (t = 0; t < 6; t++) {
            output = output << 1;
            disp_binary(output, "Auto Fantastico", delayValue);
            if (!delay(delayValue)) return 1;
        }
    } while (1);

}

int choque(int *delayValue) {
    uint8_t table[] = {
            0x81, 0x42, 0x24, 0x18,
            0x18, 0x24, 0x42
    };
    int table_size = sizeof(table) / sizeof(table[0]);
    while (1) {
        for (int i = 0; i < table_size; ++i) {
            disp_binary(table[i], "Choque", delayValue);
            if (!delay(delayValue)) return 1;
        }
    }
}

int carrera(int *delayValue) {
    uint8_t table[] = {
            0x01, 0x01, 0x02, 0x02,
            0x04, 0x04, 0x08, 0x08,
            0x11, 0x12, 0x24, 0x28,
            0x50, 0x60, 0xC0, 0x80
    };

    int table_size = sizeof(table) / sizeof(table[0]);
    while (1) {
        for (int i = 0; i < table_size; ++i) {
            disp_binary(table[i], "La Carrera", delayValue);
            if (!delay(delayValue)) return 1;
        }
    }
}

int otro(int *delayValue) {
    uint8_t table[] = {
            0x00,
            0x80,
            0xC0,
            0x60,
            0x61,
            0x62,
            0x52,
            0x4A,
            0x46,
            0x43,
            0x41,
            0x40,
            0x80,
            0x00
    };

    int table_size = sizeof(table) / sizeof(table[0]);

    while (1) {
        for (int i = 0; i < table_size; ++i) {
            disp_binary(table[i], "Ella se fue con otro", delayValue);
            if (!delay(delayValue)) return 1;
        }
    }
}

int parpadeo_estelar(int *delayValue) {

    unsigned char output;
    char t;
    bool mostrar=true;
    unsigned char vacio = 0x00;
    while (1) {
        output = 0x80;
        for (t = 0; t < 14; t++) {
            if(mostrar){
                disp_binary(output, "Parpadeo Estelar", delayValue);
                output = output >> 1;
                mostrar=false;
            } else{
                disp_binary(vacio, "Parpadeo Estelar", delayValue);
                mostrar=true;
            }
            if (!delay(delayValue)) return 1;
        }

        output = 0x01;
        for (t = 0; t < 14; t++) {
            if(mostrar){
                disp_binary(output, "Parpadeo Estelar", delayValue);
                output = output << 1;
                mostrar=false;
            } else{
                disp_binary(vacio, "Parpadeo Estelar", delayValue);
                mostrar=true;
            }
            if (!delay(delayValue)) return 1;
        }
    }
}

int fuegos_artificiales(int *delayValue) {
    uint8_t table[] = {
            0x00, 0x10, 0x38, 0x7C, 0xEE, 0xC7, 0x83,
            0x01, 0x40, 0xE0, 0xF0, 0xF8, 0xBC, 0x1E, 0x0F,
            0x07, 0x03, 0x02, 0x07, 0x0F, 0x1F,
            0x3D, 0x78, 0xF0, 0xE0, 0xC4, 0x8E, 0x1F, 0x3F,
            0x7B, 0xF1, 0xE0, 0xC0, 0x80


    };

    int table_size = sizeof(table) / sizeof(table[0]);
    while (1) {
        for (int i = 0; i < table_size; ++i) {
            disp_binary(table[i], "Fuegos Artificiales", delayValue);
            if (!delay(delayValue)) return 1;
        }
    }
}
