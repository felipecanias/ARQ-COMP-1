#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>

void disp_binary(int);
void delay(int);

void delay(int time) {
  int i;
  unsigned int j;
  for (i = time; i > 0; --i) /* repeat specified number of times */
    for (j = 0; j < 65535; ++j)
      ;
}
void disp_binary(int i) {
  int t;
  for (t = 128; t > 0; t = t / 2)
    if (i & t)
      printw("1 ");
    else
      printw("0 ");
  printw("\n");
  refresh();
}

int main() {
  char input_menu;
  int menu;
  int password = 54321;
  int password_loaded;

  initscr(); // Inicializar la biblioteca ncurses
  cbreak(); // Desactivar el búfer de línea (lectura de caracteres uno por uno)
  noecho(); // No mostrar los caracteres ingresados

  for (int i = 0; i < 3; i++) {
    printw("Ingrese su password de 5 dígitos: ");
    refresh();

    char password_input[6]; // Array para almacenar la contraseña ingresada
    int index = 0;
    char c;

    while (1) {
      c = getch();

      if (c == '\n') {
        break;
      }

      if (c == '\b') {
        if (index > 0) {
          index--;
          printw("\b \b");
          refresh();
        }
      } else {
        password_input[index] = c;
        index++;
        printw("*");
        refresh();
      }
    }

    password_input[index] = '\0';

    sscanf(password_input, "%d", &password_loaded);

    if (password_loaded == password) {
      printw("\nBienvenido al Sistema\n");
      break;
    } else {
      printw("\nContraseña no válida\n");
    }
    if (i == 2) {
      printw("\nIntentos agotados - Fin del programa\n");
      refresh();
      exit(0);
    }
  }
  
  refresh();

  printw("---Menu---\n");
  printw("1) Auto Fantastico\n");
  printw("2) Caso 2\n");
  printw("3) Caso 3\n");
  printw("4) Caso 4\n");
  printw("5) Exit\n\n");

  printw("Seleccione una opción: ");
  refresh();

  input_menu = getchar();
  menu = input_menu - '0';

  system("clear");

  switch (menu) {
  case 1:
      // Auto Fantastico
      printw("\nAuto Fantastico\n");
      unsigned char output;
      char t;
      int on_time = 10000; /* set holding time */
      printw("secuencia en acción ... Oprima una tecla para finalizar\n");
      do {
        output = 0x80;
        for (t = 0; t < 8; t++) {
          disp_binary(output);
          delay(on_time);       /* Wait a while */
          output = output >> 1; /* Shift bits to lower positions */
        }
        output = 0x01;
        for (t = 0; t < 6; t++) {
          output = output << 1;

          disp_binary(output);
          delay(on_time);
        }
      } while (1); // Modificar condicion
      output = 0x00;
      disp_binary(output);
      printw("chau... !\n");
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
      break;
  default:
      printw("\nOpción inválida\n");
      break;
  }

  getch();  // Esperar a que el usuario presione una tecla
  endwin(); // Finalizar la biblioteca ncurses

  return 0;
  }