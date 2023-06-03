#include <stdio.h>


int delay(int *d)
{
    int ch;
    int n = *d;
    int i;
    unsigned int j;
    for(i=n; i>0; --i)
        for(j=0; j<65535; ++j){
            /*
            if ((ch = getch()) != ERR) {
                switch (ch) {
                    case 0x1B: // Escape
                    case 'q':
                        return 0;
                    case KEY_UP:
                        *d -= 50;
                        n = *d;
                        break;
                    case KEY_DOWN:
                        *d += 50;
                        n = *d;
                        break;
                    default:
                        break;
                }
            }*/
        };
}

void disp_binary(int data, char *name, int *d) {
    clear();
    printw("Sequencia: %s\n\n", name);

    for (int mask = 128; mask > 0; mask=mask/2) {
        if (data & mask) addch('*');
        else addch('_');
    }
    printw("\n\nDelay: %u\n", *d);
    printw("Presione ESC o q para salir\n");
    refresh();
}
//
int auto_fantastico(int *d) {
    unsigned char output;
    char t;
    do {
        output = 0x80;
        for(t=0; t<8; t++){
            //on_time = inportb (port_in); /* Read from DIP switches */
            //outportb (port_out,~output); /* Turn LEDs on */
            disp_binary (output, "Auto Fantastico", d);
            //if (!delay(d)) return 0; /* Wait a while */
            delay(d);
            output = output>>1; /* Shift bits to lower positions */
        }
        output = 0x01;
        for(t=0; t<6; t++){
            output = output<<1;
            //on_time = inportb (port_in);
            //outportb (port_out,~output);
            disp_binary (output, "Auto Fantastico", d);
            //if (!delay(d)) return 0; /* Wait a while */
            delay(d);
        }
    } while (1); /* Repeat loop until the keyboard is hit */
    output = 0x00;
    //outportb (port_out,~output);

}

int choque(int *d){
    uint8_t table[] = {
            0x81, 0x42, 0x24, 0x18,
            0x18, 0x24, 0x42
    };
    int table_size = sizeof(table) / sizeof(table[0]);
    for (int i = 0; i < table_size; ++i) {
        disp_binary(table[i], "Choque", d);
        //if (!delay(d)) return 0; /* Wait a while */
        delay(d);
    }
    return 1;
}

int carrera(int *d) {
    uint8_t table[] = {
            0x01, 0x01, 0x02, 0x02,
            0x04, 0x04, 0x08, 0x08,
            0x11, 0x12, 0x24, 0x28,
            0x50, 0x60, 0xC0, 0x80
    };

    int table_size = sizeof(table) / sizeof(table[0]);

    for (int i = 0; i < table_size; ++i) {
        disp_binary(table[i],"La Carrera", d);
        //if (!delay(d)) return 0; /* Wait a while */
        delay(d);
    }
    return 1;
}