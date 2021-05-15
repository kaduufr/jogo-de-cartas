//
// Created by kadu on 05/05/2021.
//

#ifndef JOGO_CARTAS_CARTAS_H
#define JOGO_CARTAS_CARTAS_H

//tamanho baralho
#define TAM 65

void criarCartas(TCartas *deck);
void embaralhar(TCartas *deck, size_t n);
void empilharCartas(TCartas *deck, TCartas *carta);
int semCartas(TCartas *deck);
void iniciaDeck(TCartas *Deck);
double gerarValorDaCarta(int naipe, int numero);

char *naipes[5] = {"Pedra", "Papel", "Tesoura", "Lagarto", "Spock"};
int cartas[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};

void gerarDeck(TCartas *deck) {
  TCartas *baralho = malloc(sizeof(TCartas) * TAM);
  criarCartas(baralho);
  embaralhar(baralho, TAM);
  iniciaDeck(deck);
  for (int i = 0; i < TAM; ++i) {
      TCartas *novaCarta = (TCartas *) malloc(sizeof (TCartas));
      novaCarta->naipe = baralho[i].naipe;
      novaCarta->num = baralho[i].num;
      novaCarta->valor = gerarValorDaCarta(baralho[i].naipe, baralho[i].num);
      novaCarta->Proximo = NULL;
      empilharCartas(deck, novaCarta);
  }
}

double gerarValorDaCarta(int naipe, int numero) {
  double total;
  switch (naipe) {
    case 0:
      total = 1.0 * (double) numero;
      break;
    case 1:
      total = 1.5 * (double) numero;
      break;
    case 2:
      total = 2.0 * (double) numero;
      break;
    case 3:
      total = 2.5 * (double) numero;
      break;
    case 4:
      total = 3.0 * (double) numero;
      break;
    default:
      total = 1.0 * (double) numero;
      break;
  }
  return total;
}

void empilharCartas(TCartas *deck, TCartas *carta){
  if (semCartas(deck)) {
    deck->Proximo = carta;
  } else {
    TCartas *tmp = deck->Proximo;
    while (tmp->Proximo != NULL) {
      tmp = tmp->Proximo;
    }
    tmp->Proximo = carta;
  }
}

void criarCartas(TCartas *deck) {
  int start = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = 1; j < 14; ++j) {
      deck[start].naipe = i;
      deck[start].num = j;
      start++;
    }
  }
}

void embaralhar(TCartas *deck, size_t n)
{
  if (n > 1)
  {
    size_t i;
    for (i = 0; i < n - 1; i++)
    {
      size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
      TCartas t = deck[j];
      deck[j] = deck[i];
      deck[i] = t;
//      printf("%zu\t",deck[i].num);
    }
  }
}

int semCartas(TCartas *deck)
{
  if(deck->Proximo == NULL)
    return 1;
  else
    return 0;
}

void iniciaDeck(TCartas *Deck){
  Deck->Proximo = NULL;
}

void imprimirDeck(TCartas *deck) {
  TCartas *tmp = deck->Proximo;
  while (tmp->Proximo != NULL) {
    printf("%.2f\t", tmp->valor);
    tmp = tmp->Proximo;
  }
  printf("%.2f", tmp->valor);
}

void desempilharCarta(TCartas *deck) {
  if (semCartas(deck)) {
    puts("ta vazia");
  } else {
    TCartas *tmp = deck->Proximo;
    deck->Proximo = tmp->Proximo;
  }
}

#endif //JOGO_CARTAS_CARTAS_H
