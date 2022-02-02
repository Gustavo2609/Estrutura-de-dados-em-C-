//
// Created by danie on 17/09/2021.
//
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
  // se eu for o primeiro, o final tambem sou eu
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
  p = lista->inicio;
  while (p != NULL)
  {
    printf("chave: %d\tvalor: %d\n", p->dado.chave, p->dado.valor);
    p = p->proximo;
  }
}