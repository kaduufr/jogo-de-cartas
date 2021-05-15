//
// Created by kadu on 05/05/2021.
//

#ifndef JOGO_CARTAS_JOGADORES_H
#define JOGO_CARTAS_JOGADORES_H

#include <memory.h>

void adicionarCarta(Lista *jogador, TCartas *carta);

int tam = 0;

void iniciaListaJogadores(Lista *Lista) {
  Lista->prox = NULL;
  tam = 0;
}
int vazia(Lista *Lista)
{
  if(Lista->prox == NULL)
    return 1;
  else
    return 0;
}

Lista *alocar() {
  Lista *novo = (Lista *) malloc(sizeof(Lista));
  return novo;
}

void insereFinal(Lista *Jogadores, int value) {
  Lista *novo = alocar();
  novo->prox = NULL;
  novo->id = value;
  novo->cartas = NULL;
  char *nome = malloc(sizeof(char) * 10);
  puts("Nome do jogador:");
  fgets(nome, sizeof(char) * 10, stdin);
  novo->nome = nome;
  if (vazia(Jogadores)) {
    Jogadores->prox = novo;
  } else {
    Lista *tmp = Jogadores->prox;
    while(tmp->prox != NULL) {
      tmp = tmp->prox;
    }
    tmp->prox = novo;
  }
  tam++;
}

void imprimir(Lista *Jogadores){
  Lista *tmp = Jogadores->prox;
  while (tmp->prox != NULL) {
    printf("%s\n", tmp->nome);
    tmp = tmp->prox;
  }
  puts(tmp->nome);
}

void addJogadores (Lista *Jogadores) {
  puts("Quantos jogadores ha na mesa");
  int qtd;
  scanf("%d", &qtd);
  fflush(stdin);
  for (int i = 0; i < qtd; i++) {
    insereFinal(Jogadores, i + 1);
  }
}

void adicionarCartaAosJogadores(Lista *jogadores, TCartas *deck) {
  Lista *jogador = jogadores->prox;
  while (jogador != NULL) {
    adicionarCarta(jogador, deck);
    jogador = jogador->prox;
  }
}

void adicionarCarta(Lista *jogador, TCartas *carta) {
  TCartas *baralhoJogador = (TCartas *) malloc(sizeof(TCartas));

  for (int i = 0; i < 7; ++i) {
    TCartas *first = (TCartas *) malloc(sizeof(TCartas));
    first->num = carta->Proximo->num;
    first->naipe = carta->Proximo->naipe;
    first->valor = carta->Proximo->valor;
    first->Proximo = NULL;
    empilharCartas(baralhoJogador, first);
    desempilharCarta(carta);
  }
  jogador->cartas = baralhoJogador;
  imprimirDeck(baralhoJogador);
  puts("");
}

#endif //JOGO_CARTAS_JOGADORES_H

