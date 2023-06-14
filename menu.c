#include <stdlib.h>
#include <ncurses.h>
#include "leds.c"
#include "http.h"
// #include "include/EasyPIO.h"

// extern void otro_asm();
// extern void parpadeo_estelar_asm();


void menu()
{
    // pioInit();
    // char led[] = {14, 15, 18, 23, 24, 25, 8, 7};
    // for (int i=0; i<=7;i++){
    //     pinMode(led[i],OUTPUT);
    // }

    char *MENU = "---Menu---\n1) Auto Fantastico\n2) El Choque\n3) La Carrera\n4) Parpadeo Estelar\n5) Ella se fue con otro :(\n6) Exit\n\nSeleccione una opción";

    int opcion;
    int delays[] = {50, 50, 50, 50, 50};
    while (1)
    {
        http_return init = readLastMessage("6156973481:AAHXgfu9nLrmqucDXTX3GXREczhjTqFVY64", 0);
        uint8_t output = 0x00;
        // outportb (output);
        sendMessage("6156973481:AAHXgfu9nLrmqucDXTX3GXREczhjTqFVY64", "6022803879", MENU);

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
        refresh();

        http_return telegram_option;
        int offset = init.update_id + 1;
        do
        {
            telegram_option = readLastMessage("6156973481:AAHXgfu9nLrmqucDXTX3GXREczhjTqFVY64", offset);
            if (telegram_option.update_id != 0)
            {
                offset = telegram_option.update_id + 1;
            }
        //     printw("\n\nfin dentro dowhile: \ntext: %s\nupdate_id: %d", telegram_option.text, telegram_option.update_id);
        // refresh();
        } while (strcmp(telegram_option.text, "") == 0);

        opcion = atoi(telegram_option.text);
        // clear();

        switch (opcion)
        {

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
            // parpadeo_estelar_asm(&delays[3]);
            break;
        case 5:
            otro(&delays[4]);
            // otro_asm(&delays[4]);
            break;
            //            case 6:
            //                fuegos_artificiales(&delays[5]);
            //                break;
        case 6:
            printw("\nExit\n");
            sendMessage("6156973481:AAHXgfu9nLrmqucDXTX3GXREczhjTqFVY64", "6022803879", "Exit");
            return;
        default:
            printw("\nOpción inválida\n");
            sendMessage("6156973481:AAHXgfu9nLrmqucDXTX3GXREczhjTqFVY64", "6022803879", "Opción inválida");
            break;
        }

        clear();
    }
}
