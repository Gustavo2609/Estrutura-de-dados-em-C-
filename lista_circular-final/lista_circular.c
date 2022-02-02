//
// Created by danie on 30/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

ERRO_LISTA lista_circular_inicializar (LISTA *lista)
{
  *lista = NULL;
  return ERRO_SUCESSO;
}

ERRO_LISTA lista_circular_destruir (LISTA *lista)
{
  LISTA aux, ant;

  if (*lista != NULL)
  {
    ant = *lista;
    aux = ant->proximo;

    while (aux != *lista)
    {
      ant = aux;
      aux = aux->proximo;
      free(ant);
    }
    free(aux);

    *lista = NULL;
  }

  return ERRO_SUCESSO;
}

ERRO_LISTA lista_circular_inserir_inicio (LISTA *lista, const TIPO_DADO* dado)
{
  LISTA nova;

  nova = (LISTA) malloc(sizeof (NOH_LISTA));
  if (nova == NULL) // overflow
  {
    return ERRO_OVERFLOW;
  }

  nova->dado = *dado;

  if (*lista != NULL)
  {
    nova->proximo = (*lista)->proximo;
    (*lista)->proximo = nova;
  }
  else
  {
    nova->proximo = nova;
    *lista = nova;
  }
  return ERRO_SUCESSO;
}

ERRO_LISTA lista_circular_inserir_final (LISTA *lista, const TIPO_DADO* dado)
{
  LISTA nova;

  nova = (LISTA) malloc(sizeof (NOH_LISTA));
  if (nova == NULL) // overflow
  {
    return ERRO_OVERFLOW;
  }

  nova->dado = *dado;
  nova->proximo = nova;

  if (*lista != NULL)
  {
    nova->proximo = (*lista)->proximo;
    (*lista)->proximo = nova;
  }
  *lista = nova;

  return ERRO_SUCESSO;
}

//  Essa eh de voces...
ERRO_LISTA lista_circular_inserir_posicao (LISTA *lista, unsigned int posicao, const TIPO_DADO* dado)
{
  LISTA nova;
  LISTA aux, ant;
  unsigned int contador;

  nova = (LISTA) malloc(sizeof (NOH_LISTA));
  if (nova == NULL) // overflow
  {
    return ERRO_OVERFLOW;
  }

  nova->dado = *dado;
  nova->proximo = nova;
  contador = 0;

  if (*lista != NULL)
  {
    ant = *lista;
    aux = ant->proximo;
    do
    {
      ant = aux;
      aux = aux->proximo;
      contador++;
    } while((ant != *lista) && (contador < posicao));

    nova->proximo = aux;
    ant->proximo = nova;
  }
  else
  {
    *lista = nova;
  }
  // E ai???  Como eu vou saber se eu preciso mover o final
  // da lista para o novo no, ou se eu tenho que deixar ele
  // quietinho onde ele esta???

  return ERRO_SUCESSO;
}


ERRO_LISTA lista_circular_remover_inicio (LISTA *lista, TIPO_DADO* dado)
{
  LISTA inicio, final;

  // pre-condicao: ter nos para remover
  if (lista_circular_vazia(lista))
  {
    return ERRO_UNDERFLOW;
  }

  final = *lista;
  inicio = (*lista)->proximo;

  if (dado != NULL)
  {
    *dado = inicio->dado;
  }

  if (final == inicio)
  {
    free(*lista);
    *lista = NULL;
  }
  else
  {
    (*lista)->proximo = inicio->proximo;
    free(inicio);
  }

  return ERRO_SUCESSO;
}


ERRO_LISTA lista_circular_remover_final (LISTA *lista, TIPO_DADO* dado)
{
  LISTA aux, ant;

  // pre-condicao: ter nos para remover
  if (lista_circular_vazia(lista))
  {
    return ERRO_UNDERFLOW;
  }

  if (dado != NULL)
  {
    *dado = (*lista)->dado;
  }

  if (*lista == (*lista)->proximo)
  {
    free(*lista);
    *lista = NULL;
  }
  else
  {
    ant = *lista;
    aux = (*lista)->proximo;
    while (aux->proximo != ant)
    {
      aux = aux->proximo;
    }
    aux->proximo = aux->proximo->proximo;
    *lista = aux;
    free(ant);
  }

  return ERRO_SUCESSO;
}

//  Essa eh de voces...
ERRO_LISTA lista_circular_remover_posicao (LISTA *lista, unsigned int posicao, TIPO_DADO* dado)
{
  return ERRO_SUCESSO;
}


void lista_circular_mostrar (const LISTA *lista)
{
  LISTA aux, ant;

  if (*lista == NULL)
  {
    return;
  }

  ant = *lista;
  aux = ant->proximo;
  do
  {
    printf("%p: %d, %p\n", aux, aux->dado, aux->proximo);
    ant = aux;
    aux = aux->proximo;
  } while(ant != *lista);
}

bool lista_circular_vazia (const LISTA *lista)
{
  return (*lista == NULL);
}