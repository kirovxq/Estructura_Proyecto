#include "Cards.h"

typedef struct deck{
	int base;
	int top;
}deck;

void InitDecks(int *base, int *top);
void GoRight(card *vector, int *base, int *top, int deck);
void GoLeft(card *vector, int *base, int *top, int deck);
int PopDeck(card *vector,int base, int *top);
void PushDeck(card *vector,int *base,int *top,int deck,card c);
void PrintDeck(card *vector,int base, int top);
