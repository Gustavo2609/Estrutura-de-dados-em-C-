//
// Created by danie on 23/11/2021.
//
#include <stdlib.h>
#include "fila-prioridade.h"

ERRO_FILA fila_inicializar(FILA *fila)
{
  fila->tamanho = 0;
  fila->inicio = NULL;
  fila->final = NULL;

  return ERRO_SUCESSO;
}

ERRO_FILA fila_destruir(FILA *fila)
{
  NOH_FILA *ant, *aux;

  ant = NULL;
  aux = fila->inicio;
  while (aux != NULL)
  {
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  fila->tamanho = 0;
  fila->inicio = NULL;
  fila->final = NULL;

  return ERRO_SUCESSO;
}

ERRO_FILA fila_inserir_com_prioridade(FILA *fila, const TIPO_DADO *dado, unsigned int prioridade)
{
  NOH_FILA *novo;
  NOH_FILA *ant, *aux;

  // pre-condicao: conseguir alocar memoria
  novo = (NOH_FILA *) malloc(sizeof (NOH_FILA));
  if (novo == NULL) // nao conseguiu alocar memoria, logo...
  {
    return ERRO_OVERFLOW;
  }

  novo->dado = *dado;
  novo->prioridade = prioridade;
  novo->prox = NULL;

  ant = NULL;
  aux = fila->inicio;
  while ((aux != NULL) && (aux->prioridade >= prioridade))
  {
    ant = aux;
    aux = aux->prox;
  }

  novo->prox = aux;
  if (ant != NULL)
  {
    ant->prox = novo;
  }
  else
  {
    fila->inicio = novo;
  }

  if (novo->prox == NULL) // novo eh o ultimo noh da fila, entao...
  {
    fila->final = novo;
  }

  fila->tamanho = fila->tamanho + 1;

  return ERRO_SUCESSO;

}

ERRO_FILA fila_remover_maximo(FILA *fila, TIPO_DADO *dado, unsigned int *prioridade)
{
  NOH_FILA *aux;

  // pre-condicao: ter elementos na fila
  if (fila_vazia(fila))
  {
    return ERRO_UNDERFLOW;
  }
  aux = fila->inicio;
  fila->inicio = aux->prox;
  if (dado != NULL)
  {
    *dado = aux->dado;
  }
  if (prioridade != NULL)
  {
    *prioridade = aux->prioridade;
  }

  free(aux);
  if (fila->inicio == NULL) // removi o ultimo elemento da fila
  {
    fila->final = NULL;
  }

  fila->tamanho = fila->tamanho - 1;

  return ERRO_SUCESSO;
}

bool fila_vazia(const FILA *fila)
{
  return (fila_tamanho(fila) == 0);
}

bool fila_cheia(const FILA *fila)
{
  return false;
}

unsigned fila_tamanho(const FILA *fila)
{
  return (fila->tamanho);
}