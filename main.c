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
  char nome[20];
};

int main() {

  Cartas *deck = malloc(sizeof(Cartas) * 65);

  gerarDeck(deck);
  shuffle(deck, 65);

  return 0;
}