//
// Created by danie on 08/10/2021.
//

#ifndef LISTADUPENC_LISTADUP_H
#define LISTADUPENC_LISTADUP_H
typedef enum
{
  ERRO_SUCESSO,
  ERRO_POSICAO_INVALIDA,
  ERRO_LISTA_CHEIA,
  ERRO_LISTA_VAZIA,
  ERRO_CHAVE_INEXISTENTE
} ERRO_LISTA;

typedef struct st_registro
{
  int chave;
  int valor;
} REGISTRO;

typedef struct st_nodo
{
  REGISTRO dado;
  struct st_nodo *proximo;
  struct st_nodo *anterior;
} NODO;

typedef struct st_descritor
{
  unsigned int num_elementos;
  NODO *inicio;
  NODO *final;
} LISTA_DUP;

ERRO_LISTA lista_inicializar(LISTA_DUP *lista);
ERRO_LISTA lista_destruir(LISTA_DUP *lista);

unsigned int lista_tamanho(const LISTA_DUP *lista);
void lista_imprimir(const LISTA_DUP *lista);

ERRO_LISTA lista_inserir(LISTA_DUP *lista, REGISTRO dado, unsigned int posicao);
ERRO_LISTA lista_inserir_inicio(LISTA_DUP *lista, REGISTRO dado);
ERRO_LISTA lista_inserir_final(LISTA_DUP *lista, REGISTRO dado);
ERRO_LISTA lista_inserir_ordenado(LISTA_DUP *lista, REGISTRO dado);

ERRO_LISTA lista_remover(LISTA_DUP *lista, unsigned int posicao, REGISTRO *dado);

#endif //LISTADUPENC_LISTADUP_H
