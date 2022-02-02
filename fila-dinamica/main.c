#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

int main()
{
  FILA f;
  TIPO_DADO dado;

  srand((unsigned int) time(NULL));

  fila_inicializar(&f);

  if (fila_vazia(&f))
  {
    printf("Tudo certo. Fila vazia\n");
  }
  else
  {
    printf("Problemas. Deveria estar vazia\n");
  }

  for (int nodos = 0; nodos < 10; ++nodos)
  {
    dado = rand() % 100;
    if (fila_enfileira(&f, &dado) == ERRO_SUCESSO)
    {
      printf("Inserindo %d\n", dado);
    }
    else
    {
      printf("Erro na insercao de %d\n", dado);
    }
  }

  if (fila_cheia(&f))
  {
    printf("Isso nao ecziste\n");
  }
  else
  {
    printf("Tudo certo. Nao tem como saber se esta cheia\n");
  }

  printf("Fila com %u elementos\n", fila_tamanho(&f));

  while (fila_desenfileirar(&f, &dado) == ERRO_SUCESSO)
  {
    printf("Removendo %d da fila\n", dado);
  }

  if (fila_vazia(&f))
  {
    printf("Tudo certo. Fila vazia\n");
  }
  else
  {
    printf("Problemas. Deveria estar vazia\n");
  }

  if (fila_destruir(&f) == ERRO_SUCESSO)
  {
    printf("Fila destruida\n");
  }
  else
  {
    printf("Erro para destruir a fila\n");
  }
  return 0;
}
