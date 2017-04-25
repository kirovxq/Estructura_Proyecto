#include "Cards.h"

typedef struct deck{
	int end;
	int top;
}deck;

void InitDecks(int n, deck *s);
void PushDeck(card cards[52], deck *s, int key);
int PopDeck(card cards[52], deck *s);
void PrintDeck(card cards[52], deck s);
