//
// Created by danie on 30/11/2021.
//

#ifndef LIST_CIRCULAR_LISTA_CIRCULAR_H
#define LIST_CIRCULAR_LISTA_CIRCULAR_H
#include <stdbool.h>
typedef enum
{
  ERRO_SUCESSO,
  ERRO_OVERFLOW,
  ERRO_UNDERFLOW,
  ERRO_POSICAO_INVALIDA
} ERRO_LISTA;

typedef int TIPO_DADO;

typedef struct st_noh_lista
{
  TIPO_DADO dado;
  struct st_noh_lista* proximo;
} NOH_LISTA;

typedef NOH_LISTA* LISTA;

ERRO_LISTA lista_circular_inicializar (LISTA *lista);
ERRO_LISTA lista_circular_destruir (LISTA *lista);
bool lista_circular_vazia (const LISTA *lista);
ERRO_LISTA lista_circular_inserir_inicio (LISTA *lista, const TIPO_DADO* dado);
ERRO_LISTA lista_circular_inserir_final (LISTA *lista, const TIPO_DADO* dado);
ERRO_LISTA lista_circular_inserir_posicao (LISTA *lista, unsigned int posicao, const TIPO_DADO* dado);
ERRO_LISTA lista_circular_remover_inicio (LISTA *lista, TIPO_DADO* dado);
ERRO_LISTA lista_circular_remover_final (LISTA *lista, TIPO_DADO* dado);
ERRO_LISTA lista_circular_remover_posicao (LISTA *lista, unsigned int posicao, TIPO_DADO* dado);

void lista_circular_mostrar (const LISTA *lista);
#endif //LIST_CIRCULAR_LISTA_CIRCULAR_H
