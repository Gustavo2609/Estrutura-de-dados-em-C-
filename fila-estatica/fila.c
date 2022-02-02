//
// Created by danie on 19/11/2021.
//

#include <stdlib.h>
#include "fila.h"

ERRO_FILA fila_inicializar(FILA *fila)
{
  fila->head = 0;
  fila->tail = 0;

  return ERRO_SUCESSO;
}

ERRO_FILA fila_destruir(FILA *fila)
{
  fila->head = 0;
  fila->tail = 0;

  return ERRO_SUCESSO;
}

ERRO_FILA fila_enfileira(FILA *fila, TIPO_DADO *dado)
{
  // pre-condicao: ter espaco
  if (fila_cheia(fila))
  {
    return ERRO_OVERFLOW;
  }
  fila->dados[fila->tail] = *dado;
  fila->tail = (fila->tail + 1) % TAM_FILA;
  return ERRO_SUCESSO;
}

ERRO_FILA fila_desenfileirar(FILA *fila, TIPO_DADO *dado)
{
  // pre-condicao: ter elementos
  if (fila_vazia(fila))
  {
    return ERRO_UNDERFLOW;
  }
  if (dado != NULL)
  {
    *dado = fila->dados[fila->head];
  }
  fila->head = (fila->head + 1) % TAM_FILA;
  return ERRO_SUCESSO;
}

bool fila_vazia(const FILA *fila)
{
  return (fila->head == fila->tail);
}

bool fila_cheia(const FILA *fila)
{
  // Dois cenarios:
  // 1. tail < head: cheia, se h-t == 1
  // 2. head < tail: cheia, se t-h == TAM_FILA - 1
  if (fila->tail < fila->head)
  {
    return (fila->head - fila->tail == 1);
  }
  return (fila->tail - fila->head == (TAM_FILA - 1));
}

unsigned fila_tamanho(const FILA *fila)
{
  if (fila->tail < fila->head)
    return (fila->tail + TAM_FILA - fila->head);
  else
    return (fila->tail + 0 - fila->head);
  // (fila->tail + (fila->tail < fila->head ? TAM_FILA : 0) - fila->head);
}