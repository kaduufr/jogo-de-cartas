//
// Created by kadu on 05/05/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "menu.h"
#include "cartas.h"
#include "jogadores.h"



int main() {

  Cartas *deck = malloc(sizeof(Cartas) * 65);
  Lista *Jogadores = (Lista *) malloc(sizeof(Lista));

  iniciaListaJogadores(Jogadores);
  addJogadores(Jogadores);

  gerarDeck(deck);
  shuffle(deck, 65);

  //  inserirCarta(jogadores[0]);
  imprimir(Jogadores);
  return 0;
}