
#ifndef RACIONAL_RACIONAL_H
#define RACIONAL_RACIONAL_H

typedef struct{ /*Registro de uma estrutura ou um objeto*/ /*Estrutura de uma variavel*/
  int numerador;
  int denominador;
}RACIONAL;

int criar_racional (int a, int b, RACIONAL *r);
int somar_racionais (RACIONAL a, RACIONAL b, RACIONAL *r);
int multiplicar_racionais (RACIONAL a, RACIONAL b, RACIONAL *r);
int dividir_racionais (RACIONAL a, RACIONAL b);
int inverter_racional (RACIONAL *a);
int reduzir (RACIONAL *racional);
void mostra_racional(RACIONAL a);

#endif
