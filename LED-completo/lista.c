
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int lista_inicializar(LISTA* lista)
{
  lista->num_elementos = 0;
  lista->inicio = NULL;
  lista->final = NULL;

  return ERRO_SUCESSO;
}

int lista_destruir (LISTA *lista)
{
  while(lista_remover_inicio(lista, NULL) == ERRO_SUCESSO);
  return ERRO_SUCESSO;
}

unsigned int lista_tamanho(const LISTA* lista)
{
  return lista->num_elementos;
}
int lista_inserir_inicio(LISTA *lista, REGISTRO dado)
{
  NODO *novo;

  novo = (NODO *) malloc(sizeof (NODO));
  if (novo == NULL) // erro na alocacao de memoria
  {
    return ERRO_LISTA_CHEIA;
  }

  novo->dado = dado;
  novo->proximo = lista->inicio;
  lista->inicio = novo;
  // se eu for o primeiro nodo na lista, eu tambem sou o final da lista
  if(lista->final == NULL)
  {
    lista->final = novo;
  }
  lista->num_elementos = lista->num_elementos + 1;

  return ERRO_SUCESSO;
}

void lista_imprimir(const LISTA* lista)
{
  NODO *p;

  printf("Lista possui %u elementos\n", lista->num_elementos);
  printf("Inicio da lista..: %p\n", lista->inicio);
  printf("Final da lista...: %p\n", lista->final);
  p = lista->inicio;
  while (p != NULL)
  {
    printf("chave: %d\tvalor: %d (end: %p, prox: %p)\n", p->dado.chave, p->dado.valor, p, p->proximo);
    p = p->proximo;
  }
}

int lista_inserir_final(LISTA *lista, REGISTRO dado)
{
  NODO *novo;

  novo = (NODO *) malloc(sizeof (NODO));
  if (novo == NULL)
  {
    return ERRO_LISTA_CHEIA;
  }
  novo->dado = dado;
  novo->proximo = NULL;

  // Se eu for o primeiro, o inicio da lista aponta para mim; caso contrário
  // o final atual aponta para mim
  if (lista->final == NULL)
    lista->inicio = novo;
  else
    lista->final->proximo = novo;

  lista->final = novo;
  lista->num_elementos = lista->num_elementos + 1;

  return ERRO_SUCESSO;
}

int lista_inserir(LISTA *lista, REGISTRO dado, unsigned int posicao)
{
  NODO *novo, *aux, *ant;

  if (posicao > lista->num_elementos)
  {
    return ERRO_POSICAO_INVALIDA;
  }

  novo = (NODO *) malloc(sizeof (NODO));
  if (novo == NULL)
  {
    return ERRO_LISTA_CHEIA;
  }
  novo->dado = dado;

  ant = NULL;
  aux = lista->inicio;
  for (int i = 0; i < posicao; i++)
  {
    ant = aux;
    aux = aux->proximo;
  }

  if (aux == NULL)
  {
    lista->final = novo;
  }

  novo->proximo = aux;

  if (ant == NULL) // no inicio da lista
  {
    lista->inicio = novo;
  }
  else
  {
    ant->proximo = novo;
  }

  lista->num_elementos = lista->num_elementos + 1;
  return ERRO_SUCESSO;
}

int lista_inserir_ordenado(LISTA *lista, REGISTRO dado)
{
  NODO *novo, *aux, *ant;

  novo = (NODO *) malloc(sizeof (NODO));
  if (novo == NULL)
  {
    return ERRO_LISTA_CHEIA;
  }
  novo->dado = dado;

  ant = NULL;
  aux = lista->inicio;
  while((aux != NULL) && (aux->dado.chave < dado.chave))
  {
    ant = aux;
    aux = aux->proximo;
  }

  if (aux == NULL)
  {
    lista->final = novo;
  }

  novo->proximo = aux;

  if (ant == NULL) // no inicio da lista
  {
    lista->inicio = novo;
  }
  else
  {
    ant->proximo = novo;
  }

  lista->num_elementos = lista->num_elementos + 1;
  return ERRO_SUCESSO;
}

int lista_remover_inicio(LISTA *lista, REGISTRO *dado)
{
  NODO *t;

  if (lista->num_elementos == 0) // lista vazia
  {
    return ERRO_LISTA_VAZIA;
  }

  t = lista->inicio;
  if (dado != NULL)
  {
    *dado = t->dado;
  }

  lista->inicio = t->proximo;
  if (lista->inicio == NULL) // esvaziou a lista
  {
    lista->final = NULL;
  }
  free(t);

  lista->num_elementos = lista->num_elementos - 1;
  return ERRO_SUCESSO;
}

int lista_remover_final(LISTA *lista, REGISTRO *dado)
{
  NODO *aux, *ant;

  if (lista->num_elementos == 0) // lista vazia
  {
    return ERRO_LISTA_VAZIA;
  }

  ant = NULL;
  aux = lista->inicio;
  while(aux != lista->final)
  {
    ant = aux;
    aux = aux->proximo;
  }

  if (dado != NULL)
  {
    *dado = aux->dado;
  }

  if (ant == NULL) // removendo o primeiro e unico nodo
  {
    lista->inicio == NULL;
  }
  else
  {
    ant->proximo = NULL;
  }

  lista->final = ant;

  free(aux);
  lista->num_elementos = lista->num_elementos - 1;
  return ERRO_SUCESSO;
}

int lista_remover(LISTA *lista, unsigned int posicao, REGISTRO *dado)
{
  NODO *ant, *aux;

  if (posicao >= lista->num_elementos)
  {
    return ERRO_POSICAO_INVALIDA;
  }

  ant = NULL;
  aux = lista->inicio;
  for (int p = 0; p < posicao; p++)
  {
    ant = aux;
    aux = aux->proximo;
  }
  // aux aponta para o nodo a ser removido

  if (ant == NULL) // removendo a primeira posicao
  {
    lista->inicio = aux->proximo;
  }
  else
  {
    ant->proximo = aux->proximo;
  }

  if (dado != NULL)
  {
    *dado = aux->dado;
  }

  if (aux == lista->final) // removendo o ultimo elemento
  {
    lista->final = ant;
  }

  free(aux);
  lista->num_elementos = lista->num_elementos - 1;

  return ERRO_SUCESSO;
}

int lista_remover_chave(LISTA *lista, REGISTRO dado, unsigned int *posicao)
{
  NODO *ant, *aux;
  unsigned int p;

  if (lista->num_elementos == 0)
  {
    return ERRO_LISTA_VAZIA;
  }

  ant = NULL;
  aux = lista->inicio;
  p = 0;
  // Se a lista fosse ordenada, a condicao do While seria
  // ((aux != NULL) && (aux->dado.chave < dado.chave))
  while ((aux != NULL) && (aux->dado.chave != dado.chave))
  {
    ant = aux;
    aux = aux->proximo;
    p = p + 1;
  }

  if (aux == NULL) // chegou no final sem encontrar a chave
  {
    return ERRO_CHAVE_INEXISTENTE;
  }

  // Se a lista fosse ordenada, precisa ver se saiu na chave correta
  // if (aux->dado.chave != dado.chave)
  // {
  //   return ERRO_CHAVE_INEXISTENTE;
  // }

  // aux aponta para o nodo a ser removido

  if (ant == NULL) // removendo a primeira posicao
  {
    lista->inicio = aux->proximo;
  }
  else
  {
    ant->proximo = aux->proximo;
  }

  if (posicao != NULL)
  {
    *posicao = p;
  }

  if (aux == lista->final) // removendo o ultimo elemento
  {
    lista->final = ant;
  }

  free(aux);
  lista->num_elementos = lista->num_elementos - 1;

  return ERRO_SUCESSO;


}

int lista_buscar(const LISTA *lista, REGISTRO dado, unsigned int *posicao)
{
  NODO *aux;
  unsigned int p;

  if (lista->num_elementos == 0)
  {
    return ERRO_LISTA_VAZIA;
  }

  aux = lista->inicio;
  p = 0;
  while ((aux != NULL) && (aux->dado.chave != dado.chave))
  {
    aux = aux->proximo;
    p = p + 1;
  }

  if (aux == NULL) // chegou no final sem encontrar a chave
  {
    return ERRO_CHAVE_INEXISTENTE;
  }

  if (posicao != NULL)
  {
    *posicao = p;
  }

  return ERRO_SUCESSO;
}

int lista_ordenada_buscar(const LISTA *lista, REGISTRO dado, unsigned int *posicao)
{
  NODO *aux;
  unsigned int p;

  if (lista->num_elementos == 0)
  {
    return ERRO_LISTA_VAZIA;
  }

  aux = lista->inicio;
  p = 0;
  while ((aux != NULL) && (aux->dado.chave < dado.chave))
  {
    aux = aux->proximo;
    p = p + 1;
  }

  if (aux == NULL) // chegou no final sem encontrar a chave
  {
    return ERRO_CHAVE_INEXISTENTE;
  }

  if (aux->dado.chave != dado.chave)
  {
    return ERRO_CHAVE_INEXISTENTE;
  }

  if (posicao != NULL)
  {
    *posicao = p;
  }

  return ERRO_SUCESSO;
}
