//
// Created by danie on 23/11/2021.
//

#ifndef FILA_PRIORIDADE_FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_FILA_PRIORIDADE_H
#include <stdbool.h>
typedef int TIPO_DADO;

typedef enum
{
  ERRO_SUCESSO,
  ERRO_OVERFLOW,
  ERRO_UNDERFLOW
}ERRO_FILA;

typedef struct st_noh_fila
{
  TIPO_DADO dado;
  unsigned int prioridade;
  struct st_noh_fila* prox;
} NOH_FILA;

typedef struct st_fila
{
  unsigned int tamanho;
  NOH_FILA *inicio;
  NOH_FILA *final;
} FILA;

ERRO_FILA fila_inicializar(FILA *fila);
ERRO_FILA fila_destruir(FILA *fila);
ERRO_FILA fila_inserir_com_prioridade(FILA *fila, const TIPO_DADO *dado, unsigned int prioridade);
ERRO_FILA fila_remover_maximo(FILA *fila, TIPO_DADO *dado, unsigned int *prioridade);
bool fila_vazia(const FILA *fila);
bool fila_cheia(const FILA *fila);
unsigned fila_tamanho(const FILA *fila);

#endif //FILA_PRIORIDADE_FILA_PRIORIDADE_H
