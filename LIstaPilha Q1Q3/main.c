#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pilha.h"

bool str1Cstr2(char *str, unsigned int tamanho);
bool palindroma (char *cadeia, unsigned int tamanho);

int main()
{
  char cadeia[] = "ABABBACABBABA";
  char frase[] = "socorram-me subi no onibus em marrocos";
  //char frase[] = "luza rocelina, a namorada do manuel, leu na moda da romana: anil e cor azul.";
  //char frase[] = "me ve se a panela da moca e de aco, madalena paes, e vem.";
  //char frase[] = "seco de raiva, coloco no colo caviar e doces";

  if (str1Cstr2(cadeia, strlen(cadeia)))
  {
    printf("Ok\n");
  }
  else
  {
    printf("Moio\n");
  }

  if (palindroma(frase, strlen(frase)))
  {
    printf("eh palindroma\n");
  }
  else
  {
    printf("Nao eh palindroma\n");
  }

  return 0;
}


bool str1Cstr2(char *str, unsigned int tamanho)
{
  PILHA temp;
  char *p;
  char letra;

  pilha_inicializar(&temp);
  p = str;
  while (*p != 'C')
  {
    pilha_PUSH(&temp, p);
    p++;
  }
  // chegou no meio
  p++;
  while ((pilha_POP(&temp, &letra) == ERRO_SUCESSO) && (*p != '\0'))
  {
    if (letra != *p)
      return false;
    p++;
  }

  if (pilha_esta_vazia(&temp) && (*p == '\0'))
    return true;
  else
    return false;

}

bool palindroma (char *cadeia, unsigned int tamanho)
{
  PILHA letras;
  char letra;
  char *posicao;

  pilha_inicializar(&letras);
  posicao = cadeia;
  while (*posicao != '\0')
  {
    if (*posicao >= 'a' && *posicao <= 'z')
      pilha_PUSH(&letras, posicao);
    posicao++;
  }
  // A pilha tem todas as letras da frase
  posicao = cadeia;
  while (pilha_POP(&letras, &letra) == ERRO_SUCESSO)
  {
    while (*posicao < 'a' || *posicao > 'z')
      posicao++;
    if (letra != *posicao)
      return false;
    posicao++;
  }
  return true;
}