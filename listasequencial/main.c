#include <stdio.h>
#include <stdlib.h>
#include "listasequencial.h"

// lista é um conjunto de elementos sobre o quais conseguimos
// definir uma relação de precedência
//
// -- L(i-1) ocupa a posicao anterior ao L(i), que ocupa a posição
//    anterior ao L(i+1)

int main()
{
  LISTA lista;
  TIPO_DADO dado;
  unsigned int posicao;

  if (lista_inicializar(&lista) != ERRO_SUCESSO)
  {
    printf("Problemas na inicialização da lista\n");
    exit(1);
  }

  lista_imprimir(&lista);

  lista_inserir_ordenado(&lista, 4);
  lista_inserir_ordenado(&lista, 3);
  lista_inserir_ordenado(&lista, 9);
  lista_inserir_ordenado(&lista, 1);
  lista_inserir_ordenado(&lista, 6);
  lista_inserir_ordenado(&lista, 2);

  lista_imprimir(&lista);

  dado = 3;
  if (lista_ordenada_buscar(&lista, dado, &posicao) == ERRO_SUCESSO)
  {
    printf("Chave %d na posicao %u\n", dado, posicao);
  }
  else
  {
    printf("Chave nao encontrada\n");
  }

  dado = 3;
  if (lista_remover_chave(&lista, dado, &posicao) == ERRO_SUCESSO)
  {
    printf("Chave %d removida da posicao %u\n", dado, posicao);
  }
  else
  {
    printf("Chave nao encontrada\n");
  }

  lista_imprimir(&lista);

  if (lista_inserir(&lista, 1, 0) != ERRO_SUCESSO)
  {
    printf("Erro na insercao\n");
  }
  else
  {
    printf("Insercao com sucesso\n");
  }

  if (lista_inserir(&lista, 2, 0) != ERRO_SUCESSO)
  {
    printf("Erro na insercao\n");
  }
  else
  {
    printf("Insercao com sucesso\n");
  }

  if (lista_inserir(&lista, 3, 0) != ERRO_SUCESSO)
  {
    printf("Erro na insercao\n");
  }
  else
  {
    printf("Insercao com sucesso\n");
  }

  if (lista_inserir(&lista, 4, 3) != ERRO_SUCESSO)
  {
    printf("Erro na insercao\n");
  }
  else
  {
    printf("Insercao com sucesso\n");
  }

  lista_imprimir(&lista);

  if (lista_remover(&lista, 7, NULL) == ERRO_SUCESSO)
  {
    printf("Temos um problema da remocao\n");
  }

  if (lista_remover(&lista, 3, &dado) == ERRO_SUCESSO)
  {
    printf("Removemos o %d\n", dado);
  }

  if (lista_remover(&lista, 0, &dado) == ERRO_SUCESSO)
  {
    printf("Removemos o %d\n", dado);
  }

  lista_imprimir(&lista);

  dado = 3;
  if (lista_buscar(&lista, dado, &posicao) == ERRO_SUCESSO)
  {
    printf("Chave %d na posicao %u\n", dado, posicao);
  }
  else
  {
    printf("Chave nao encontrada\n");
  }

  return 0;
}
