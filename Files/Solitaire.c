#include <stdio.h>
#include "Decks.h"

void ShuffleCards(card *vector,int *base,int *top,card *cards){
	int i,cont=0,k=0;
	Randomize(cards);
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
	for(i = 0; i < 7; i++){
		vector[top[i]].state='V';
		printf("Deck: %d\n",i+1);
		ShowCard(vector[top[i]]);
		//PrintDeck(vector, base[i],top[i]);
	}
}

void	PassCard(card *vector, int *base, int *top, int deck1, int deck2){
	int card=PopDeck(base,top, deck1);
	if(card!=-1){
		PushDeck(vector,base,top,deck2,vector[card]);
		if(top[deck1]!=base[deck1])
			vector[top[deck1]].state='V';
	}else
		printf("Deck %d is empty!",deck1+1);
}

void main(){
	card cards[52];
	AddValueCards(cards);
	int base[13],top[13];
	InitDecks(base,top);
	card vector[60];
	ShuffleCards(vector,base,top,cards);
	int i,j;	
	do{
		printf("Indique movimiento de carta: 1 -> 2: ");
		scanf("%d %d",&i,&j);
		system("clear");
		for(i = 0; i < 7; i++){
			printf("Deck: %d\n",i+1);
			ShowCard(vector[top[i]]);
		}
		if( vector[top[i]].number==vector[top[j]].number-1 && vector[top[i]].color != vector[top[j]].color)
			PassCard(vector,base,top,3,4);
		else
			printf("No se puede hacer el cambio\n");
	}while(i!=-1);
}
