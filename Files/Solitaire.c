#include <stdio.h>
#include "Decks.h"

void main(){
	card cards[52];
	AddValueCards(cards);
	Randomize(cards);
	deck decks[13];
	InitDecks(13, decks);
	int i,cont=0,k=0;
	for(i = 0; i < 28; i++){
		if(k==7){
			cont++;
			k=cont;
		}
		PushDeck(cards, &decks[k], i);
		k++;
	}
	for(i = 28; i < 52; i++)//the rest of the cards
		PushDeck(cards, &decks[7], i);
	//PrintCards(cards);
	for(i = 0; i < 7; i++){
		cards[decks[i].top].state='V';
		ShowCard(cards[decks[i].top]);
		//PrintDeck(cards, decks[i]);
	}
}
