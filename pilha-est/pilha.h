//
// Created by danie on 19/10/2021.
//
#ifndef PILHA_EST_PILHA_H
#define PILHA_EST_PILHA_H
#include <stdbool.h>
#define TAM_PILHA 3

typedef int TIPO_DADO;

typedef struct st_pilha
{
  TIPO_DADO dados[TAM_PILHA];
  unsigned int topo;
} PILHA;

typedef enum
{
  ERRO_SUCESSO,
  ERRO_OVERFLOW,
  ERRO_UNDERFLOW
} ERRO_PILHA;

ERRO_PILHA pilha_inicializar (PILHA *pilha);
ERRO_PILHA pilha_destruir (PILHA *pilha);
ERRO_PILHA pilha_PUSH (PILHA *pilha, const TIPO_DADO *dado);
ERRO_PILHA pilha_POP (PILHA *pilha, TIPO_DADO *dado);
ERRO_PILHA pilha_PEEK (PILHA *pilha, TIPO_DADO *dado);
bool pilha_esta_cheia(const PILHA *pilha);
bool pilha_esta_vazia(const PILHA *pilha);
#endif //PILHA_EST_PILHA_H
