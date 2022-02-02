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

ERRO_LISTA lista_circular_inserir_posicao (LISTA *lista, unsigned int posicao, const TIPO_DADO* dado)
{
  LISTA nova;
  LISTA aux, ant;

  nova = (LISTA) malloc(sizeof (NOH_LISTA));
  if (nova == NULL) // overflow
  {
    return ERRO_OVERFLOW;
  }

  nova->dado = *dado;
  nova->proximo = nova;

  if (*lista != NULL)
  {
    ant = *lista;
    aux = ant->proximo;
    for (unsigned int contador = 0; contador < posicao; ++contador)
    {
      ant = aux;
      aux = aux->proximo;
    }
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


ERRO_LISTA lista_circular_remover_inicio (LISTA *lista, TIPO_DADO* dado);
ERRO_LISTA lista_circular_remover_final (LISTA *lista, TIPO_DADO* dado);
ERRO_LISTA lista_circular_remover_posicao (LISTA *lista, unsigned int posicao, TIPO_DADO* dado);


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