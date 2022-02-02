//
// Created by danie on 31/08/2021.
//
#include <stdio.h>
#include "listasequencial.h"

int lista_inicializar(LISTA* lista)
{
  lista->tamanho = 0;
  return ERRO_SUCESSO;
}

unsigned int lista_tamanho(const LISTA* lista)
{
  return lista->tamanho;
}

int lista_inserir(LISTA *lista, TIPO_DADO dado, unsigned int posicao)
{
  // Pre-condicao
  // 1. Tem que ter espaco na lista
  // 2. Tem que ser uma posicao valida (0 e tamanho)
  if (lista->tamanho == TAM_LISTA)
  {
    return ERRO_LISTA_CHEIA;
  }
  if ((posicao > lista->tamanho) || (posicao >= TAM_LISTA))
  {
    return ERRO_POSICAO_INVALIDA;
  }

  // posicao = 0
  // |2|1| | | | | | ==> |2|1|
  // +-+-+-+-+-+-+-+
  //  0 1 2
  // Jogar uma posicao pra frente todo mundo do final ate a posicao
  for (unsigned int indice = lista->tamanho; indice > posicao; indice--)
  {
    lista->nodos[indice] = lista->nodos[indice - 1];
  }
  lista->nodos[posicao] = dado;
  lista->tamanho = lista->tamanho + 1;
  return ERRO_SUCESSO;
}

int lista_inserir_ordenado(LISTA *lista, TIPO_DADO dado)
{
  unsigned int posicao;
  // Pre-condicao
  // 1. ter espaco na lista
  if (lista->tamanho == TAM_LISTA)
  {
    return ERRO_LISTA_CHEIA;
  }

  // Jogar para a direita ENQUANTO nao chegar no inicio da lista e
  // houver elemento maior que o que estqa sendo inserido aa esquerda
  for(posicao = lista->tamanho; posicao > 0; posicao--)
  {
    if (lista->nodos[posicao - 1] <= dado)
    {
      break;
    }
    lista->nodos[posicao] = lista->nodos[posicao - 1];
  }
  lista->nodos[posicao] = dado;
  lista->tamanho = lista->tamanho + 1;

  return ERRO_SUCESSO;
}

int lista_remover(LISTA *lista, unsigned int posicao, TIPO_DADO *dado)
{
  // Pre-condicao
  // 1. Ter elementos na lista
  // 2. Ser uma posicao valida
  if (lista->tamanho == 0)
  {
    return ERRO_LISTA_VAZIA;
  }
  if (posicao >= lista->tamanho)
  {
    return ERRO_POSICAO_INVALIDA;
  }

  // volta o valor da posicao para o programa principal
  if (dado != NULL)
  {
    *dado = lista->nodos[posicao];
  }
  // posicao = 0
  // |2|1|3| | | | | ==> |1|3| |
  // +-+-+-+-+-+-+-+
  //  0 1 2
  // Jogar uma posicao pra tras todo mundo da posicao ate o final
  for (unsigned int indice = posicao + 1; indice <= lista->tamanho - 1; indice++)
  {
    lista->nodos[indice - 1] = lista->nodos[indice];
  }
  lista->tamanho = lista->tamanho - 1;
  return ERRO_SUCESSO;
}

void lista_imprimir(const LISTA* lista)
{
  printf("Lista com %u elementos\n", lista->tamanho);
  for (unsigned int posicao = 0; posicao < lista->tamanho; ++posicao)
  {
    printf("[%03u]: %d\n", posicao, lista->nodos[posicao]);
  }
}

int lista_buscar(const LISTA *lista, TIPO_DADO dado, unsigned int *posicao)
{
  unsigned int indice;
  for(indice = 0; indice < lista->tamanho; indice++)
  {
    if (lista->nodos[indice] == dado)
    {
      if (posicao != NULL)
      {
        *posicao = indice;
      }
      break;
    }
  }
  if (indice == lista->tamanho) // foi ate o final da lista e nao saiu por break;
  {
    return ERRO_CHAVE_INEXISTENTE;
  }
  else
  {
    return ERRO_SUCESSO;
  }
}

int lista_ordenada_buscar(const LISTA *lista, TIPO_DADO dado, unsigned int *posicao)
{
  unsigned int indice;

  for(indice = 0; indice < lista->tamanho && lista->nodos[indice] < dado; indice++);

  if ((indice != lista->tamanho) && (lista->nodos[indice] == dado))
  {
    if (posicao != NULL)
      *posicao = indice;
    return ERRO_SUCESSO;
  }
  else
  {
    return ERRO_CHAVE_INEXISTENTE;
  }
}

int lista_remover_chave(LISTA *lista, TIPO_DADO dado, unsigned int *posicao)
{
  unsigned int indice;

  if (lista_buscar(lista, dado, posicao) != ERRO_SUCESSO)
  {
     return ERRO_CHAVE_INEXISTENTE;
  }
  lista_remover(lista, *posicao, NULL);
  return ERRO_SUCESSO;

  /*
  for(indice = 0; indice < lista->tamanho && lista->nodos[indice] != dado; indice++);
  if (indice == lista->tamanho) // nao achou
  {
    return ERRO_CHAVE_INEXISTENTE;
  }
  if (posicao != NULL)
    *posicao = indice;
  for(indice = *posicao + 1; indice < lista->tamanho; indice++)
  {
    lista->nodos[indice - 1] = lista->nodos[indice];
  }
  lista->tamanho = lista->tamanho - 1;
  return ERRO_SUCESSO;
   */
}

int lista_inserir_inicio(LISTA *lista, TIPO_DADO dado)
{
  return lista_inserir(lista, dado, 0);
}

int lista_inserir_final(LISTA *lista, TIPO_DADO dado)
{
  return lista_inserir(lista, dado, lista_tamanho(lista));
}

int lista_remover_inicio(LISTA *lista, TIPO_DADO *dado)
{
  return lista_remover(lista, 0, dado);
}

int lista_remover_final(LISTA *lista, TIPO_DADO *dado)
{
  //return lista_remover(lista, lista_tamanho(lista) == 0 ? 0 : lista_tamanho(lista) - 1, dado);
  unsigned int t;
  t = lista_tamanho(lista);
  if (t == 0)
    return ERRO_LISTA_VAZIA;
  return lista_remover(lista, t - 1, dado);
}
