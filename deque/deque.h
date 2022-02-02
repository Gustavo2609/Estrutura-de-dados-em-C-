//
// Created by danie on 26/11/2021.
//

#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H
typedef int TIPO_DADO;

typedef struct st_nodo_deque
{
  TIPO_DADO dado;
  struct st_nodo_deque *proximo;
  struct st_nodo_deque *anterior;
} NODO_DEQUE;

typedef struct st_descritor
{
  unsigned int num_elementos;
  NODO_DEQUE *front;
  NODO_DEQUE *back;
} DEQUE;

typedef enum
{
  ERRO_SUCESSO,
  ERRO_OVERFLOW,
  ERRO_UNDERFLOW
} ERRO_DEQUE;

ERRO_DEQUE deque_inicializar(DEQUE *deque);
ERRO_DEQUE deque_destruir (DEQUE *deque);

ERRO_DEQUE deque_push_front (DEQUE *deque, const TIPO_DADO *dado);
ERRO_DEQUE deque_pop_front (DEQUE *deque, TIPO_DADO *dado);
ERRO_DEQUE deque_front (DEQUE *deque, TIPO_DADO *dado);

ERRO_DEQUE deque_push_back (DEQUE *deque, const TIPO_DADO *dado);
ERRO_DEQUE deque_pop_back (DEQUE *deque, TIPO_DADO *dado);
ERRO_DEQUE deque_back (DEQUE *deque, TIPO_DADO *dado);

unsigned int deque_tamanho (const DEQUE *deque);

#endif //DEQUE_DEQUE_H
