#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila-prioridade.h"

int main()
{
  FILA f;
  TIPO_DADO dado;
  unsigned int prioridade;

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
    if (fila_inserir_com_prioridade(&f, &dado, dado) == ERRO_SUCESSO)
    {
      printf("Inserindo %d com prioridade %u\n", dado, dado);
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

  while (fila_remover_maximo(&f, &dado, &prioridade) == ERRO_SUCESSO)
  {
    printf("Removendo %d da fila, que tinha prioridade %u\n", dado, prioridade);
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
