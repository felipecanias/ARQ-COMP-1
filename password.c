#include <ncurses.h>
#include <stdlib.h>

int main() {
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
  }


  printw("Programa Finalizado!\n");
  refresh();

  getch();  // Esperar a que el usuario presione una tecla
  endwin(); // Finalizar la biblioteca ncurses

  return 0;
}
