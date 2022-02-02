#include <stdio.h>
#include "utilitarios.h"
#include "racional.h"

int criar_racional (int a, int b, RACIONAL *r)
{
  // pre-condicao
  if (b == 0)
  {
    return ERRO_DENOMINADOR_ZERO;
  }
  //pos-condicao
  r->numerador = a;
  //(*r).numerador = a;
  r->denominador = b;
  return ERRO_SUCESSO;
}

int somar_racionais (RACIONAL a, RACIONAL b, RACIONAL *r)
{
  r->numerador = a.numerador * b.denominador + b.numerador * a.denominador;
  r->denominador = a.denominador * b.denominador;
  return ERRO_SUCESSO;
}

int multiplicar_racionais (RACIONAL a, RACIONAL b, RACIONAL *r)
{
  r->numerador = a.numerador * b.numerador;
  r->denominador = a.denominador * b.denominador;
  return ERRO_SUCESSO;
}

int inverter_racional (RACIONAL *a)
{
  int t1, t2;
  // pre-condicao
  if (a->numerador == 0)
  {
    return ERRO_IMPOSSIVEL_INVERTER;
  }

  // t1 = a->numerador;
  // t2 = a->denominador;
  // a->numerador = t2;
  // a->denominador = t1;

  return criar_racional(a->denominador, a->numerador, a);
}

/*int dividir_racionais (RACIONAL a, RACIONAL b, RACIONAL *r)
{
  // pre-condicao
  if (b.numerador == 0)
  { // Solucao oinc, oinc...
    printf("[ERRO :: Racional] Denominador nao pode ser zero\n");
    exit(1);
  }

  return (multiplicar_racionais(a, inverter_racional(b)));
}
*/
void mostra_racional(RACIONAL a)
{
  // Solucao oinc, oinc...
  printf("%d/%d", a.numerador, a.denominador);
}

int reduzir (RACIONAL *racional)
{
  int a, b, resto;
  RACIONAL novo;

  if (racional->numerador > racional->denominador)
  {
    a = racional->numerador;
    b = racional->denominador;
  }
  else
  {
    a = racional->denominador;
    b = racional->numerador;
  }
  // Algoritmo de Euclides
  while (b != 0)
  {
    resto = a % b;
    a = b;
    b = resto;
  }
  // a eh o MDC entre a e b
  racional->numerador = racional->numerador / a;
  racional->denominador = racional->denominador / a;

  return ERRO_SUCESSO;
}