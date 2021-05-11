//
// Created by kadu on 05/05/2021.
//

#ifndef JOGO_CARTAS_JOGADORES_H
#define JOGO_CARTAS_JOGADORES_H

struct Jogador {
  int id;
  struct Jogador *prox;
  Cartas cartas;
};
typedef struct Jogador Lista;

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
    printf("%d\n", tmp->id);
    tmp = tmp->prox;
  }
  printf("%d\n", tmp->id);
}

void addJogadores (Lista *Jogadores) {
  puts("Quantos jogadores ha na mesa");
  int qtd;
  char *nome = malloc(sizeof(char) * 10);
  scanf("%d", &qtd);
  fflush(stdin);
  for (int i = 0; i < qtd; i++) {
    insereFinal(Jogadores, i + 1);
  }
}

#endif //JOGO_CARTAS_JOGADORES_H

