#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
  LISTA l;
  REGISTRO reg;

  if (lista_inicializar(&l) != ERRO_SUCESSO)
  {
    printf("Problemas para inicializar a lista\n");
    exit(1);
  }

  for (int i = 0; i < 4; ++i)
  {
    reg.chave = i;
    reg.valor = i;
    if (lista_inserir_inicio(&l, reg) != ERRO_SUCESSO)
    {
      printf("Erro na insercao do no\n");
    }
  }

  lista_imprimir(&l);
  return 0;
}
