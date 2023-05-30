#include <stdio.h>
//
void disp_binary(int);
void delay(int);
//
int main() {
  unsigned char output;
  char t;
  int on_time = 10000;  //set holding time
  printf("secuencia en acción ... Oprima una tecla para finalizar\n");
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
  printf("chau... !\n");

  return 0;
}
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
      printf("1 ");
    else
      printf("0 ");
  printf("\n");
}