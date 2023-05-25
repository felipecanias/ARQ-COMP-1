#include <conio.h>
#include <stdio.h>

int main() {
  int password = 54321;
  int password_loaded;

  for (int i = 0; i < 3; i++) {
    printf("Ingrese su password de 5 dígitos: ");

    char password_input[6]; // Array para almacenar la contraseña ingresada
    int index = 0;
    char c;

    while (1) {
        c = getch();

        if (c == '\r') { 
            break;
        }

        if (c == '\b') { 
            if (index > 0) {
            index--;
            printf("\b \b");
            }
        } else {
            password_input[index] = c;
            index++;
            printf("*");
        }
    }

    sscanf(password_input, "%d",
           &password_loaded); 

    if (password_loaded == password) {
      printf("\nBienvenido al Sistema\n");
      break; 
    } else {
      printf("\nContraseña no válida\n");
    }
  }

  printf("Programa Finalizado!\n");

  return 0;
}
