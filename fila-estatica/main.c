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

  do
  {
    dado = rand() % 100;
    printf("Inserindo %d\n", dado);
  } while(fila_enfileira(&f, &dado) == ERRO_SUCESSO);

  if (fila_cheia(&f))
  {
    printf("Tudo certo. Fila cheia\n");
  }
  else
  {
    printf("Problemas. Deveria estar cheia\n");
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
