#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main()
{
  PILHA p;
  char expressao[] = "8-(8*(A/7)+9*8/(7–4))*(8+B)";
  unsigned int tamanho;
  char dado;
  bool erro;

  pilha_inicializar(&p);

  tamanho = strlen(expressao);
  erro = false;
  for (int posicao = 0; posicao < tamanho; ++posicao)
  {
    if (expressao[posicao] == '(')
    {
      pilha_PUSH(&p, &expressao[posicao]);
    }
    if (expressao[posicao] == ')')
    {
      if (pilha_POP(&p, &dado) == ERRO_UNDERFLOW)
      {
        erro = true;
        break;
      }
    }
  }

  if ((!erro) && pilha_esta_vazia(&p))
  {
    printf("Expressao com parenteses corretos");
  }
  else
  {
    printf("Erro na expressao");
  }

  return 0;
}
