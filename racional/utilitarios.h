//
// Created by danie on 20/08/2021.
//

#ifndef RACIONAL_UTILITARIOS_H
#define RACIONAL_UTILITARIOS_H

int LeInteiro();
double LeDouble();

typedef enum
{
  ERRO_SUCESSO,
  ERRO_DENOMINADOR_ZERO,
  ERRO_IMPOSSIVEL_INVERTER
} ERRO_RACIONAL;

#endif //RACIONAL_UTILITARIOS_H
