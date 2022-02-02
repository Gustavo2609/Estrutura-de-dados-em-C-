//
// Created by danie on 17/09/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int lista_inicializar(LISTA* lista)
{
  lista->num_elementos = 0;
  lista->inicio = NULL;
  lista->final = NULL;

  return ERRO_SUCESSO;
}

int lista_inserir_inicio(LISTA *lista, REGISTRO dado)
{
  NODO *novo;

  novo = (NODO *) malloc(sizeof (NODO));
  if (novo == NULL) // erro na alocacao de memoria
  {
    return ERRO_LISTA_CHEIA;
  }

  novo->dado = dado;
  novo->proximo = lista->inicio;
  lista->inicio = novo;
  // se eu for o primeiro nodo na lista, eu tambem sou o final da lista
  if(lista->final == NULL)
  {
    lista->final = novo;
  }
  lista->num_elementos = lista->num_elementos + 1;

  return ERRO_SUCESSO;
}

void lista_imprimir(const LISTA* lista)
{
  NODO *p;

  printf("Lista possui %u elementos\n", lista->num_elementos);
  p = lista->inicio;
  while (p != NULL)
  {
    printf("chave: %d\tvalor: %d\n", p->dado.chave, p->dado.valor);
    p = p->proximo;
  }
}

int lista_inserir_final(LISTA *lista, REGISTRO dado)
{
  NODO *novo;

  novo = (NODO *) malloc(sizeof (NODO));
  if (novo == NULL)
  {
    return ERRO_LISTA_CHEIA;
  }
  novo->dado = dado;
  novo->proximo = NULL;

  // Se eu for o primeiro, o inicio da lista aponta para mim; caso contrário
  // o final atual aponta para mim
  if (lista->final == NULL)
    lista->inicio = novo;
  else
    lista->final->proximo = novo;

  lista->final = novo;
  lista->num_elementos = lista->num_elementos + 1;

  return ERRO_SUCESSO;
}

int lista_inserir(LISTA *lista, REGISTRO dado, unsigned int posicao)
{
  NODO *novo, *aux, *ant;

  if (posicao > lista->num_elementos)
  {
    return ERRO_POSICAO_INVALIDA;
  }

  novo = (NODO *) malloc(sizeof (NODO));
  if (novo == NULL)
  {
    return ERRO_LISTA_CHEIA;
  }
  novo->dado = dado;

  ant = NULL;
  aux = lista->inicio;
  for (int i = 0; i < posicao; i++)
  {
    ant = aux;
    aux = aux->proximo;
  }

  if (aux == NULL)
  {
    lista->final = novo;
  }

  novo->proximo = aux;

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

int lista_inserir_ordenado(LISTA *lista, REGISTRO dado)
{
  NODO *novo, *aux, *ant;

  novo = (NODO *) malloc(sizeof (NODO));
  if (novo == NULL)
  {
    return ERRO_LISTA_CHEIA;
  }
  novo->dado = dado;

  ant = NULL;
  aux = lista->inicio;
  while((aux != NULL) && (aux->dado.chave < dado.chave))
  {
    ant = aux;
    aux = aux->proximo;
  }

  if (aux == NULL)
  {
    lista->final = novo;
  }

  novo->proximo = aux;

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

int lista_remover_inicio(LISTA *lista, REGISTRO *dado)
{
  NODO *t;

  if (lista->num_elementos == 0) // lista vazia
  {
    return ERRO_LISTA_VAZIA;
  }

  t = lista->inicio;
  if (dado != NULL)
  {
    *dado = t->dado;
  }

  lista->inicio = t->proximo;
  if (lista->inicio == NULL) // esvaziou a lista
  {
    lista->final = NULL;
  }
  free(t);

  lista->num_elementos = lista->num_elementos - 1;
  return ERRO_SUCESSO;
}

int lista_remover_final(LISTA *lista, REGISTRO *dado)
{

}