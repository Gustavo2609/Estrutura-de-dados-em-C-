//
// Created by danie on 19/10/2021.
//
#include <stdio.h>
#include <stdbool.h>
#include "pilha.h"

ERRO_PILHA pilha_inicializar (PILHA *pilha)
{
  pilha->topo = 0;
  return ERRO_SUCESSO;
}

ERRO_PILHA pilha_destruir (PILHA *pilha)
{
  pilha->topo = 0;
  return ERRO_SUCESSO;
}

ERRO_PILHA pilha_PUSH (PILHA *pilha, const TIPO_DADO *dado)
{
  // pre-condicao
  // Precisa ter espaco...
  if (pilha_esta_cheia(pilha))
  {
    return ERRO_OVERFLOW;
  }
  pilha->dados[pilha->topo] = *dado;
  pilha->topo = pilha->topo + 1;
  return ERRO_SUCESSO;
}

ERRO_PILHA pilha_POP (PILHA *pilha, TIPO_DADO *dado)
{
  // pre-condicao
  // Nao pode estar vazia
  if (pilha_esta_vazia(pilha))
  {
    return ERRO_UNDERFLOW;
  }
  pilha->topo = pilha->topo - 1;
  if (dado != NULL)
  {
    *dado = pilha->dados[pilha->topo];
  }
  return ERRO_SUCESSO;
}

ERRO_PILHA pilha_PEEK (PILHA *pilha, TIPO_DADO *dado)
{
  // pre-condicao
  // Pilha nao pode estar vazia
  if (pilha_esta_vazia(pilha))
  {
    return ERRO_UNDERFLOW;
  }
  if (dado != NULL)
  {
    *dado = pilha->dados[pilha->topo - 1];
  }
  return ERRO_SUCESSO;
}

bool pilha_esta_cheia(const PILHA *pilha)
{
  return (pilha->topo == TAM_PILHA);
}

bool pilha_esta_vazia(const PILHA *pilha)
{
  return (pilha->topo == 0);
}