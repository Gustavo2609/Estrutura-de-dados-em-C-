#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "utilitarios.h"

//criar a função de ler inteiro
int LeInteiro()
{
  int numero;
  char buffer[4096];
  char *ptrfinal;
  do
  {
    while(!fgets(buffer, 4096, stdin));
    buffer[strcspn(buffer, "\n")] = '\0';
    errno = 0;
    ptrfinal = NULL;
    numero = strtol(buffer, &ptrfinal, 10);
  } while ((errno == ERANGE) || (ptrfinal == buffer) || (*ptrfinal && *ptrfinal != '\n'));
  return (int) numero;
}

double LeDouble()
{
  double numero;
  char buffer[4096];
  char *ptrfinal;

  do
  {
    while(!fgets(buffer, 4096, stdin));
    buffer[strcspn(buffer, "\n")] = '\0';
    errno = 0;
    ptrfinal = NULL;
    numero = strtod(buffer, &ptrfinal);
  } while ((errno == ERANGE) || (ptrfinal == buffer) || (*ptrfinal && *ptrfinal != '\n'));

  return numero;
}