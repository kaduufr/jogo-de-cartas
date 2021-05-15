//
// Created by kadu on 05/05/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structs.h"
#include "menu.h"
#include "cartas.h"
#include "jogadores.h"



int main() {

  TCartas *deck = (TCartas *) malloc(sizeof(TCartas));
  Lista *Jogadores = (Lista *) malloc(sizeof(Lista));

  iniciaListaJogadores(Jogadores);
  addJogadores(Jogadores);

  gerarDeck(deck);
  adicionarCartaAosJogadores(Jogadores, deck);
  return 0;
}
