//
// Created by danie on 26/11/2021.
//
#include <stdlib.h>
#include "deque.h"

ERRO_DEQUE deque_inicializar(DEQUE *deque)
{
  deque->num_elementos = 0;
  deque->front = NULL;
  deque->back = NULL;

  return ERRO_SUCESSO;
}
ERRO_DEQUE deque_destruir (DEQUE *deque)
{
  NODO_DEQUE *ant, *aux;

  ant = NULL;
  aux = deque->back;
  while (aux != NULL)
  {
    ant = aux;
    aux = aux->anterior;
    free(ant);
  }

  deque->num_elementos = 0;
  deque->front = NULL;
  deque->back = NULL;

  return ERRO_SUCESSO;
}

ERRO_DEQUE deque_push_front (DEQUE *deque, const TIPO_DADO *dado)
{
  NODO_DEQUE *novo;

  // pre-condicao: ter espaco
  novo = (NODO_DEQUE *) malloc(sizeof (NODO_DEQUE));
  if (novo == NULL) // encheu...
  {
    return ERRO_OVERFLOW;
  }

  novo->dado = *dado;
  novo->anterior = NULL;
  novo->proximo = deque->front;
  if (deque->front == NULL) // primeiro elemento do deque
  {
    deque->back = novo;
  }
  else
  {
    deque->front->anterior = novo;
  }

  deque->front = novo;
  deque->num_elementos = deque->num_elementos + 1;

  return ERRO_SUCESSO;
}

ERRO_DEQUE deque_pop_front (DEQUE *deque, TIPO_DADO *dado)
{
  NODO_DEQUE *aux;

  // pre-condicao: ter elementos
  if (deque_tamanho(deque) == 0)
  {
    return ERRO_UNDERFLOW;
  }

  aux = deque->front;
  if (dado != NULL)
  {
    *dado = aux->dado;
  }
  deque->front = aux->proximo;
  free(aux);

  if (deque->front == NULL) // removeu ultimo elemento
  {
    deque->back = NULL;
  }
  else
  {
    deque->front->anterior = NULL;
  }

  deque->num_elementos = deque->num_elementos - 1;

  return ERRO_SUCESSO;
}

ERRO_DEQUE deque_front (DEQUE *deque, TIPO_DADO *dado)
{
  // pre-condicao: ter elementos
  if (deque_tamanho(deque) == 0)
  {
    return ERRO_UNDERFLOW;
  }

  if (dado != NULL)
  {
    *dado = deque->front->dado;
  }

  return ERRO_SUCESSO;
}

ERRO_DEQUE deque_push_back (DEQUE *deque, const TIPO_DADO *dado)
{
  NODO_DEQUE *novo;

  // pre-condicao: ter espaco
  novo = (NODO_DEQUE *) malloc(sizeof (NODO_DEQUE));
  if (novo == NULL) // encheu...
  {
    return ERRO_OVERFLOW;
  }

  novo->dado = *dado;
  novo->proximo = NULL;
  novo->anterior = deque->back;
  if (deque->back == NULL) // primeiro elemento do deque
  {
    deque->front = novo;
  }
  else
  {
    deque->back = novo;
  }
  deque->back = novo;
  deque->num_elementos = deque->num_elementos + 1;

  return ERRO_SUCESSO;
}

ERRO_DEQUE deque_pop_back (DEQUE *deque, TIPO_DADO *dado)
{
  NODO_DEQUE *aux;
  // pre-condicao: ter elementos
  if (deque_tamanho(deque) == 0)
  {
    return ERRO_UNDERFLOW;
  }

  aux = deque->back;
  if (dado != NULL)
  {
    *dado = aux->dado;
  }
  deque->back = aux->anterior;
  free(aux);

  if (deque->back == NULL) // removeu ultimo elemento
  {
    deque->front = NULL;
  }
  else
  {
    deque->back->proximo = NULL;
  }

  deque->num_elementos = deque->num_elementos - 1;

  return ERRO_SUCESSO;
}

ERRO_DEQUE deque_back (DEQUE *deque, TIPO_DADO *dado)
{
  // pre-condicao: ter elementos
  if (deque_tamanho(deque) == 0)
  {
    return ERRO_UNDERFLOW;
  }

  if (dado != NULL)
  {
    *dado = deque->back->dado;
  }

  return ERRO_SUCESSO;
}

unsigned int deque_tamanho (const DEQUE *deque)
{
  return deque->num_elementos;
}
