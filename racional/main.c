#include <stdio.h>
#include <stdlib.h>
#include "utilitarios.h"
#include "racional.h"

int main()
{
  RACIONAL r1, r2;
  RACIONAL s;
  int n, d;

  printf("Para o primeiro racional, digite o numerador: ");
  n = LeInteiro();

  printf("Para o primeiro racional, digite o denominador: ");
  d = LeInteiro();

  if (criar_racional(n, d, &r1) == ERRO_DENOMINADOR_ZERO)
  {
    printf("Nao da para criar esse racional\n");
    exit(1);
  }

  printf("O primeiro racional vale ");
  mostra_racional(r1);
  putchar('\n');

  printf("Para o segundo racional, digite o numerador: ");
  n = LeInteiro();
  printf("Para o segundo racional, digite o denominador: ");
  d = LeInteiro();
  if (criar_racional(n, d, &r2) == ERRO_DENOMINADOR_ZERO)
  {
    printf("Nao da para criar esse racional\n");
    exit(1);
  }

  printf("O segundo racional vale ");
  mostra_racional(r2);
  putchar('\n');


  somar_racionais(r1, r2, &s);
  reduzir(&s);
  printf("A soma deles vale ");
  mostra_racional(s);
  putchar('\n');

/*  s = reduzir(multiplicar_racionais(r1, r2));
  printf("O produto deles vale ");
  mostra_racional(s);
  putchar('\n');

  s = reduzir(dividir_racionais(r1, r2));
  printf("A razao entre eles vale ");
  mostra_racional(s);
  putchar('\n');

  s = inverter_racional(r1);
  printf("O inverso do primeiro vale ");
  mostra_racional(s);
  putchar('\n');
*/
  return 0;
}
