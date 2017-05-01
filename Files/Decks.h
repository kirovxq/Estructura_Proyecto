#include "Cards.h"

typedef struct deck{
	int base;
	int top;
}deck;

void InitDecks(int *base, int *top);
int PopDeck(int *base, int *top, int deck);
void PushDeck(card *vector,int *base,int *top,int deck,card c);
void PrintDeck(card *vector,int base, int top);
