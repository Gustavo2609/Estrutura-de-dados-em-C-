#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista_circular.h"

int main()
{
  LISTA l;
  int dado;

  srand((unsigned int) time(NULL));

  lista_circular_inicializar(&l);
  if (lista_circular_vazia(&l))
  {
    printf("A lista esta vazia... Tudo certo\n");
  }
  else
  {
    printf("A lista NAO esta vazia... Tudo errado\n");
  }

  for (int contador = 0; contador < 2; ++contador)
  {
    dado = rand() % 100;
    if (lista_circular_inserir_inicio(&l, &dado) == ERRO_SUCESSO)
    {
      printf("Sucesso na insercao de %d no inicio\n", dado);
    }
    else
    {
      printf("Erro na insercao de %d no inicio\n", dado);
    }
  }

  for (int contador = 0; contador < 2; ++contador)
  {
    dado = rand() % 100;
    if (lista_circular_inserir_final(&l, &dado) == ERRO_SUCESSO)
    {
      printf("Sucesso na insercao de %d final\n", dado);
    }
    else
    {
      printf("Erro na insercao de %d final\n", dado);
    }
  }

  lista_circular_mostrar(&l);

  if (lista_circular_remover_inicio(&l, &dado) == ERRO_SUCESSO)
  {
    printf("Removeu %d do inicio da lista\n", dado);
  }
  else
  {
    printf("Erro na remocao do inicio da lista\n");
  }

  printf("Lista depois de remover\n");
  lista_circular_mostrar(&l);

  if (lista_circular_remover_final(&l, &dado) == ERRO_SUCESSO)
  {
    printf("Removeu %d do final da lista\n", dado);
  }
  else
  {
    printf("Erro na remocao do final da lista\n");
  }

  printf("Lista depois de remover\n");
  lista_circular_mostrar(&l);

  lista_circular_destruir(&l);

  printf("Lista depois de ser destruida\n");
  lista_circular_mostrar(&l);

  dado = rand() % 100;
  lista_circular_inserir_final(&l, &dado);
  printf("Lista antes de remover\n");
  lista_circular_mostrar(&l);
  dado = 999;
  lista_circular_remover_final(&l, &dado);
  printf("Removendo o unico elemento do final da lista: %d\n", dado);

  printf("Lista depois de remover\n");
  lista_circular_mostrar(&l);


  dado = rand() % 100;
  lista_circular_inserir_inicio(&l, &dado);
  printf("Lista antes de remover\n");
  lista_circular_mostrar(&l);
  dado = 999;
  lista_circular_remover_inicio(&l, &dado);
  printf("Removendo o unico elemento do inicio da lista: %d\n", dado);

  printf("Lista depois de remover\n");
  lista_circular_mostrar(&l);

  return 0;
}
