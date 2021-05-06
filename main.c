//
// Created by kadu on 05/05/2021.
//
#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "cartas.h"
#include "jogadores.h"


struct player {
  int id;
  char nome[20]
};

typedef struct cartas {
  int num;
  int naipe;
} Cartas;

int main() {

  Cartas *deck = malloc(sizeof(Cartas) * 65);
  deck[0].naipe = 1;
  deck[0].num = 1;

  printf("%d", deck[0].num);

  return 0;
}