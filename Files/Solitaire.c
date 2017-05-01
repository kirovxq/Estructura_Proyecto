#include <stdio.h>
#include "Decks.h"

void main(){
	card cards[52];
	AddValueCards(cards);
	Randomize(cards);
	int base[13],top[13];
	InitDecks(base,top);
	card vector[60];
	int i,cont=0,k=0;
	for(i = 0; i < 28; i++){
		if(k==7){
			cont++;
			k=cont;
		}
		PushDeck(vector,base,top,k,cards[i]);
		k++;
	}
	for(i = 28; i < 52; i++)//the rest of the cards
		PushDeck(vector,base,top,7,cards[i]);
	//PrintCards(cards);
	for(i = 0; i < 7; i++){
		vector[top[i]].state='V';
		ShowCard(vector[top[i]]);
		//PrintDeck(cards, decks[i]);
	}
}
