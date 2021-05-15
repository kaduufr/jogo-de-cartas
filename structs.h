//
// Created by Kadu on 12/05/2021.
//

#ifndef JOGO_CARTAS_STRUCTS_H
#define JOGO_CARTAS_STRUCTS_H

struct cartas {
  int num;
  int naipe;
  double valor;
  struct cartas *Proximo;
} ;

typedef struct cartas TCartas;

struct Jogador {
  int id;
  struct Jogador *prox;
  char *nome;
  TCartas *cartas;
};
typedef struct Jogador Lista;

#endif //JOGO_CARTAS_STRUCTS_H
