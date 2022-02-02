#include <stdio.h>
typedef enum
{
  ERRO_SUCESSO,
  ERRO_CHAVE_INEXISTENTE
} ERRO_BUSCABINARIA;

int busca_binaria (int chave, int v[], int lim_inf, int lim_sup, int *posicao);
int busca_binaria_i (int chave, int v[], int lim_inf, int lim_sup, int *posicao);

int main()
{
  int chave, posicao;
  int dados[] = {3, 9, 12, 16, 17, 19, 22};

  scanf("%d", &chave);
  if (busca_binaria_i(chave, dados, 0, 6, &posicao) == ERRO_SUCESSO)
  {
    printf("A chave %d esta na posicao %d\n", chave, posicao);
  }
  else
  {
    printf("A chave %d nao existe\n", chave);
  }
  return 0;
}
/* GARANTIR: vetor tem que estar ordenado
 * Procura no meio do vetor
 * Se encontrar,
 *   retorna a posicao
 * Se nao encontrar
 *   Se o que esta buscando for MAIOR do que o que encontrou, chama busca binaria
 *      no que restou aa direita do meio
 *   Se o que esta buscando for MENOR do que o que encontrou, chama busca binaria
 *      no que restou a esquerda do meio
 */
// Busca binaria RECURSIVA
int busca_binaria (int chave, int v[], int lim_inf, int lim_sup, int *posicao)
{
  int meio;

  if (lim_inf > lim_sup) // limites cruzados --> chave nao existe!
  {
    return ERRO_CHAVE_INEXISTENTE;
  }
  meio = lim_inf + (lim_sup - lim_inf) / 2;
  if (v[meio] == chave) // encontrei!
  {
    if (posicao != NULL)
      *posicao = meio;
    return ERRO_SUCESSO;
  }

  if (chave > v[meio]) // chave eh maior
  {
    return busca_binaria(chave, v, meio + 1, lim_sup, posicao);
  }
  else // chave eh menor
  {
    return busca_binaria(chave, v, lim_inf, meio - 1, posicao);
  }
}

// Busca binaria ITERATIVA
int busca_binaria_i (int chave, int v[], int lim_inf, int lim_sup, int *posicao)
{
  int meio;

  while (lim_inf <= lim_sup)
  {
    meio = lim_inf + (lim_sup - lim_inf) / 2;
    if (v[meio] == chave) // encontrei!
    {
      if (posicao != NULL)
        *posicao = meio;
      return ERRO_SUCESSO;
    }
    if (chave > v[meio]) // chave eh maior
    {
      lim_inf = meio + 1;
    }
    else
    {
      lim_sup = meio - 1;
    }
  }
  return ERRO_CHAVE_INEXISTENTE;
}