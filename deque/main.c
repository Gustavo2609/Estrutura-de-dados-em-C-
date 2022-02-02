#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deque.h"

int main()
{
  const unsigned int TAM = 4;
  DEQUE d;
  TIPO_DADO dado;

  srand((unsigned int) time(NULL));

  deque_inicializar(&d);

  for (int i = 0; i < TAM; ++i)
  {
    dado = rand() % 100;
    if (deque_push_front(&d, &dado) == ERRO_SUCESSO)
    {
      printf("Push front do valor %d\n", dado);
    }
    else
    {
      printf("Problema no push_front\n");
    }
  }

  if (deque_tamanho(&d) == TAM)
  {
    printf("Tudo certo ate agora. Temos %u elementos no deque\n", TAM);
  }
  else
  {
    printf("Problemas. Deveriamos ter %u elementos no deque, mas temos %u\n", TAM, deque_tamanho(&d));
  }

  if (deque_pop_back(&d, &dado) == ERRO_SUCESSO)
  {
    printf("Pop back retornou %d\n", dado);
  }
  else
  {
    printf("Problema no pop back\n");
  }

  if (deque_pop_front(&d, &dado) == ERRO_SUCESSO)
  {
    printf("Pop front retornou %d\n", dado);
  }
  else
  {
    printf("Problema no pop back\n");
  }

  for (int i = 0; i < TAM; ++i)
  {
    dado = rand() % 100;
    if (deque_push_back(&d, &dado) == ERRO_SUCESSO)
    {
      printf("Push back do valor %d\n", dado);
    }
    else
    {
      printf("Problema no push_back\n");
    }
  }

  printf("Tamanho atual do deque: %u\n", deque_tamanho(&d));

  if (deque_front(&d, &dado) == ERRO_SUCESSO)
  {
    printf("O inicio do deque tem %d\n", dado);
  }
  else
  {
    printf("Problemas para peek_front\n");
  }

  if (deque_back(&d, &dado) == ERRO_SUCESSO)
  {
    printf("O final do deque tem %d\n", dado);
  }
  else
  {
    printf("Problemas para peek_back\n");
  }

  if (deque_destruir(&d) == ERRO_SUCESSO)
  {
    printf("Deque destruido e ficou com tamanho %u\n", deque_tamanho(&d));
  }
  else
  {
    printf("Problemas para destruir o deque, que ficou com %u elementos\n", deque_tamanho(&d));
  }

  return 0;
}
