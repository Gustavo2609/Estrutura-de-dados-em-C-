#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

int main()
{
  LISTA l;
  REGISTRO reg;
  int valor;

  srand((unsigned int) time(NULL));

  if (lista_inicializar(&l) != ERRO_SUCESSO)
  {
    printf("Problemas para inicializar a lista\n");
    exit(1);
  }

  for (int i = 0; i < 3; ++i)
  {
    valor = rand() % 100;
    reg.chave = valor;
    reg.valor = valor;
    if (lista_inserir_ordenado(&l, reg) != ERRO_SUCESSO)
    {
      printf("Erro na insercao do no\n");
    }
  }

  lista_imprimir(&l);

  while(lista_remover_inicio(&l, &reg) == ERRO_SUCESSO)
  {
    printf("Removi %d\n", reg.chave);
  }

  return 0;
}
