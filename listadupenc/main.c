#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listadup.h"

int main()
{
  LISTA_DUP lista;
  REGISTRO dado;
  int numero;

  srand((unsigned int) time(NULL));

  if (lista_inicializar(&lista) != ERRO_SUCESSO)
  {
    printf("Erro na inicializacao da lista\n");
    exit(1);
  }

  lista_imprimir(&lista);

  for(int i = 0; i < 5; i++)
  {
    numero = rand() % 100;
    dado.chave = numero;
    dado.valor = numero;
    if (lista_inserir_ordenado(&lista, dado) != ERRO_SUCESSO)
    {
      printf("Erro na insercao ordenada\n");
      exit(1);
    }
  }

/*  dado.chave = 99;
  dado.valor = 99;
  if (lista_inserir(&lista, dado, lista_tamanho(&lista)) != ERRO_SUCESSO)
  {
    printf("Erro na insercao no final lista\n");
    exit(1);
  }

  dado.chave = 45;
  dado.valor = 45;
  if (lista_inserir(&lista, dado, lista_tamanho(&lista) / 2) != ERRO_SUCESSO)
  {
    printf("Erro na insercao no meio lista\n");
    exit(1);
  }
*/
  lista_imprimir(&lista);

  if (lista_destruir(&lista) != ERRO_SUCESSO)
  {
    printf("Erro na destruicao da lista\n");
    exit(1);
  }
  return 0;
}
