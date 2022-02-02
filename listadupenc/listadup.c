//
// Created by danie on 08/10/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "listadup.h"

ERRO_LISTA lista_inicializar(LISTA_DUP* lista)
{
  lista->inicio = NULL;
  lista->final = NULL;
  lista->num_elementos = 0;

  return ERRO_SUCESSO;
}

ERRO_LISTA lista_destruir (LISTA_DUP *lista)
{
  NODO *ant, *aux;

  ant = NULL;
  aux = lista->inicio;
  while (aux != NULL)
  {
    ant = aux;
    aux = aux->proximo;
    free (ant);
  }

  return lista_inicializar(lista);
}

unsigned int lista_tamanho(const LISTA_DUP *lista)
{
  return lista->num_elementos;

  /*
   * Se eu NAO TIVESSE o no descritor, teria que andar na
   * lista contando os nodos
  unsigned int tamanho;
  NODO *aux;

  tamanho = 0;
  aux = lista->inicio;
  while (aux != NULL)
  {
    tamanho = tamanho + 1;
    aux = aux->proximo;
  }

  return tamanho;
   */
}

ERRO_LISTA lista_inserir(LISTA_DUP *lista, REGISTRO dado, unsigned int posicao)
{
  NODO *novo;
  NODO *ant, *aux;

  // Pre-condicao
  if (posicao > lista_tamanho(lista))
  {
    return ERRO_POSICAO_INVALIDA;
  }

  // Pre-condicao
  novo = (NODO *) malloc(sizeof (NODO));
  if (novo == NULL)
  {
    return ERRO_LISTA_CHEIA;
  }

  novo->dado = dado;
  ant = NULL;
  aux = lista->inicio;
  for(unsigned int i = 0; i < posicao; i++)
  {
    ant = aux;
    aux = aux->proximo;
  }

  if (aux == NULL) // no final da lista
  {
    lista->final = novo;
  }
  else
  {
    aux->anterior = novo;
  }

  novo->proximo = aux;
  novo->anterior = ant;

  if (ant == NULL) // no inicio da lista
  {
    lista->inicio = novo;
  }
  else
  {
    ant->proximo = novo;
  }

  lista->num_elementos = lista->num_elementos + 1;
  return ERRO_SUCESSO;
}

void lista_imprimir(const LISTA_DUP *lista)
{
  NODO *aux;

  printf("Lista possui %u elementos\n", lista->num_elementos);
  printf("Inicio da lista..: %p\n", lista->inicio);
  printf("Final da lista...: %p\n", lista->final);

  aux = lista->inicio;
  while (aux != NULL)
  {
    printf("chave: %d\tvalor: %d (ant: %p, end: %p, prox: %p)\n",
           aux->dado.chave, aux->dado.valor, aux->anterior, aux, aux->proximo);
    aux = aux->proximo;
  }
}

ERRO_LISTA lista_inserir_inicio(LISTA_DUP *lista, REGISTRO dado)
{
  return (lista_inserir(lista, dado, 0));
}

ERRO_LISTA lista_inserir_final(LISTA_DUP *lista, REGISTRO dado)
{
  return (lista_inserir(lista, dado, lista_tamanho(lista)));
}

ERRO_LISTA lista_inserir_ordenado(LISTA_DUP *lista, REGISTRO dado)
{
  NODO *novo;
  NODO *ant, *aux;

  // Pre-condicao
  novo = (NODO *) malloc(sizeof (NODO));
  if (novo == NULL)
  {
    return ERRO_LISTA_CHEIA;
  }

  novo->dado = dado;
  ant = NULL;
  aux = lista->inicio;
  while ((aux != NULL) && (aux->dado.chave < dado.chave))
  {
    ant = aux;
    aux = aux->proximo;
  }

  if (aux == NULL) // no final da lista
  {
    lista->final = novo;
  }
  else
  {
    aux->anterior = novo;
  }

  novo->proximo = aux;
  novo->anterior = ant;

  if (ant == NULL) // no inicio da lista
  {
    lista->inicio = novo;
  }
  else
  {
    ant->proximo = novo;
  }

  lista->num_elementos = lista->num_elementos + 1;
  return ERRO_SUCESSO;
}

ERRO_LISTA lista_remover(LISTA_DUP *lista, unsigned int posicao, REGISTRO *dado)
{
  /*
   * Testar a pre-condicao (posicao tem que ser valida)
   * Andar na lista ate a posicao
   * Remover o no e ajustar os ponteiros aux->anterior e ant->proximo
   * Decrementar o numero de elementos na lista
   */
}