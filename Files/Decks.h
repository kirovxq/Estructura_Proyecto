#include "Cards.h"

typedef struct deck{
	int base;
	int top;
}deck;
/*
void InitDecks(int *base, int *top);
int PopDeck(int *base, int *top, int deck);
void PushDeck(card *vector,int *base,int *top,int deck,card c);
void PrintDeck(card *vector,int base, int top);
*/

void InitDecks(deck *decks);
int PopDeck(deck *decks, int key);
void ShiftRight(card *vector, deck *decks, int key);
void ShiftLeft(card *vector, deck *decks, int key);
void PushDeck(card *vector, deck *decks, int key,card c);
void PrintDeck(card *vector,deck *decks, int key);
