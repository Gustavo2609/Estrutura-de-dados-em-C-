
#ifndef LISTAED_LISTA_H
#define LISTAED_LISTA_H

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
} NODO;

typedef struct st_descritor {
  unsigned int num_elementos;
  NODO *inicio;
  NODO *final;
} LISTA;

int lista_inicializar(LISTA* lista);
int lista_destruir (LISTA *lista);

unsigned int lista_tamanho(const LISTA* lista);

int lista_inserir(LISTA *lista, REGISTRO dado, unsigned int posicao);
int lista_inserir_inicio(LISTA *lista, REGISTRO dado);
int lista_inserir_final(LISTA *lista, REGISTRO dado);
int lista_inserir_ordenado(LISTA *lista, REGISTRO dado);

int lista_remover(LISTA *lista, unsigned int posicao, REGISTRO *dado);
int lista_remover_inicio(LISTA *lista, REGISTRO *dado);
int lista_remover_final(LISTA *lista, REGISTRO *dado);
int lista_remover_chave(LISTA *lista, REGISTRO dado, unsigned int *posicao);

int lista_buscar(const LISTA *lista, REGISTRO dado, unsigned int *posicao);
int lista_ordenada_buscar(const LISTA *lista, REGISTRO dado, unsigned int *posicao);

void lista_imprimir(const LISTA* lista);
#endif //LISTAED_LISTA_H
