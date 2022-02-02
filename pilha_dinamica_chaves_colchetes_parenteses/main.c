#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main()
{
  PILHA p;
  char expressao[] = "{A+C*[J-4]*[G+I]-(K*9)-L}";
  unsigned int tamanho;
  char dado, simbolo;
  bool erro;

  pilha_inicializar(&p);

  tamanho = strlen(expressao);
  erro = false;
  for (int posicao = 0; posicao < tamanho && !erro; ++posicao)
  {
    simbolo = expressao[posicao];
    if ((simbolo == '(') || (simbolo == '[') || (simbolo == '{'))
      pilha_PUSH(&p, &simbolo);
    if ((simbolo == ')') || (simbolo == ']') || (simbolo == '}'))
    {
      if (pilha_POP(&p, &dado) == ERRO_UNDERFLOW)
      {
        erro = true;
        continue;
      }
      switch (dado)
      {
        case '(':
          if (simbolo != ')')
            erro = true;
          break;
        case '[':
          if (simbolo != ']')
            erro = true;
          break;
        case '{':
          if (simbolo != '}')
            erro = true;
          break;
        default:
          erro = true;
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
