//
// Created by danie on 05/11/2021.
//

#ifndef PILHA_DINAMICA_PILHA_H
#define PILHA_DINAMICA_PILHA_H
#include <stdbool.h>

typedef char TIPO_DADO;

typedef struct st_no_pilha
{
  TIPO_DADO dado;
  struct st_no_pilha *sucessor;
} NO_PILHA;

typedef NO_PILHA *PILHA;

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

#endif //PILHA_DINAMICA_PILHA_H
