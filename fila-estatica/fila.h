//
// Created by danie on 19/11/2021.
//

#ifndef FILA_ESTATICA_FILA_H
#define FILA_ESTATICA_FILA_H

#include <stdbool.h>
#define TAM_FILA 10
typedef int TIPO_DADO;

typedef enum
{
  ERRO_SUCESSO,
  ERRO_OVERFLOW,
  ERRO_UNDERFLOW
}ERRO_FILA;

typedef struct st_fila
{
  TIPO_DADO dados[TAM_FILA];
  unsigned int head;
  unsigned int tail;
} FILA;

ERRO_FILA fila_inicializar(FILA *fila);
ERRO_FILA fila_destruir(FILA *fila);
ERRO_FILA fila_enfileira(FILA *fila, TIPO_DADO *dado);
ERRO_FILA fila_desenfileirar(FILA *fila, TIPO_DADO *dado);
bool fila_vazia(const FILA *fila);
bool fila_cheia(const FILA *fila);
unsigned fila_tamanho(const FILA *fila);

#endif //FILA_ESTATICA_FILA_H
