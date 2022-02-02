#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha.h"

int main()
{
  PILHA p;
  TIPO_DADO v;

  srand((unsigned int) time(NULL));

  if (pilha_inicializar(&p) != ERRO_SUCESSO)
  {
    printf("Erro na inicializacao da pilha\n");
    exit(1);
  }

  if (pilha_esta_vazia(&p))
  {
    printf("Pilha esta vazia\n");
  }
  else
  {
    printf("Erro na inicializacao da pilha (nao esta vazia)\n");
    exit(1);
  }

  do
  {
    v = rand() % 100;
    printf("Empilhando %d\n", v);
  } while (pilha_PUSH(&p, &v) == ERRO_SUCESSO);
  printf("Pilha encheu...\n");

  if (pilha_esta_cheia(&p))
  {
    printf("Pilha esta cheia\n");
  }
  else
  {
    printf("Algo de errado... Pilha deveria estar cheia\n");
    exit(1);
  }

  if (pilha_PEEK(&p, &v) == ERRO_SUCESSO)
  {
    printf("Mostrando o topo da pilha: %d\n", v);
  }
  else
  {
    printf("Algo de errado... Pilha deveria ter alguma coisa\n");
    exit(1);
  }

  while (pilha_POP(&p, &v) == ERRO_SUCESSO)
  {
    printf("Retirei %d da pilha\n", v);
  }
  printf("Pilha esvaziou...\n");

  if (pilha_esta_vazia(&p))
  {
    printf("Pilha esta vazia\n");
  }
  else
  {
    printf("Alguma coisa deu errado. Deveria esta vazia\n");
    exit(1);
  }

  if(pilha_destruir(&p) == ERRO_SUCESSO)
  {
    printf("Pilha destruida...\n");
  }
  else
  {
    printf("Erro na destruicao da pilha\n");
    exit(1);
  }

  if (pilha_esta_vazia(&p))
  {
    printf("Pilha esta vazia\n");
  }
  else
  {
    printf("Alguma coisa deu errado. Deveria esta vazia\n");
    exit(1);
  }
  return 0;
}
