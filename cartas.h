//
// Created by kadu on 05/05/2021.
//

#ifndef JOGO_CARTAS_CARTAS_H
#define JOGO_CARTAS_CARTAS_H

typedef struct cartas {
  int num;
  int naipe;
  struct cartas *Proximo;
} Cartas;

typedef struct cartas TCartas;

char *naipes[5] = {"Pedra", "Papel", "Tesoura", "Lagarto", "Spock"};
int cartas[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

void gerarDeck(Cartas *deck) {
  int start = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = 1; j < 14; ++j) {
      deck[start].naipe = i;
      deck[start].num = j;
      start++;
    }
  }
}

// embaralha o deck
void shuffle(Cartas *deck, size_t n)
{
  if (n > 1)
  {
    size_t i;
    for (i = 0; i < n - 1; i++)
    {
      size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
      Cartas t = deck[j];
      deck[j] = deck[i];
      deck[i] = t;
//      printf("%zu\t",deck[i].num);
    }
  }
}

int semCartas(TCartas *Lista)
{
  if(Lista->Proximo == NULL)
    return 1;
  else
    return 0;
}



#endif //JOGO_CARTAS_CARTAS_H
