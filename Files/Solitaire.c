#include <stdio.h>
#include "Decks.h"

void ShuffleCards(card *vector, deck *decks,card *cards){
	int i,cont=0,k=0;
	Randomize(cards);
	for(i = 0; i < 28; i++){
		if(k==7){
			cont++;
			k=cont;
		}
		PushDeck(vector,decks,k,cards[i]);
		k++;
	}
	for(i = 28; i < 52; i++)//the rest of the cards
		PushDeck(vector,decks,7,cards[i]);
	for(i = 0; i < 7; i++){
		vector[decks[i].top].state='V';
		ShowCard(vector[decks[i].top]);
		//PrintDeck(vector, decks,i);
	}
}
void	PassCard(card *vector, deck *decks, int from, int to){
	int card=PopDeck(decks, from);
	if(card!=-1){
		PushDeck(vector, decks, to, vector[card]);
		if(decks[from].top!=decks[from].base)
			vector[decks[from].top].state='V';
	}else
		printf("Deck %d is empty!",from+1);
}


void main(){
	card cards[52];
	AddValueCards(cards);
	int base[13],top[13];
	deck decks[13];
	InitDecks(decks);
	card vector[60];
	ShuffleCards(vector,decks,cards);
	int i,j;	
	do{
		printf("Indique movimiento de carta: 1 -> 2: ");
		scanf("%d %d",&i,&j);
		system("clear");
		for(i = 0; i < 7; i++){
			printf("**********\nDeck: %d",i+1);
			printf("\n**********\n");
			ShowCard(vector[decks[i].top]);
		}
		if( vector[decks[i].top].number==vector[decks[j].top].number-1 && 
			vector[decks[i].top].color != vector[decks[j].top].color)
			PassCard(vector,decks,i,j);
		else
			printf("No se puede hacer el cambio\n");
	}while(i!=-1);
}
