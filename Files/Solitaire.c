#include <stdio.h>
#include "Decks.h"

void ShuffleCards(card *vector, deck *decks,card *cards);
void PassCard(card *vector, deck *decks, int orig, int dest);
void MoveCard(card *vector,deck *decks);
void RandomizeDiscard(card *vector, deck *decks);

void main(){
	card cards[52];
	AddValueCards(cards);
	deck decks[13];
	InitDecks(decks);
	card vector[60];
	ShuffleCards(vector,decks,cards);
	int i,opt=0;
	do{
		for(i = 0; i < 7; i++){
			printf("**********\nDeck: %d",i+1);
			printf("\n**********\n");
			ShowCard(vector[decks[i].top]);
		}
		printf("**********\nDiscard");
		printf("\n**********\n");
		ShowCard(vector[decks[7].top]);
		printf("\nMenu\n===========\n");
		printf("1) Mover carta\n");
		printf("2) Pedir carta\n");
		printf("3) Salir\n");
		do{
			printf("Opcion: ");scanf("%d",&opt);
		}while(opt<1 & opt>3);
		switch(opt){
			case 1: MoveCard(vector,decks); break;
			case 2: RandomizeDiscard(vector, decks); break;
		}
	}while(opt!=3);
}

//************************************************************

void	PassCard(card *vector, deck *decks, int orig, int dest){
	int card=PopDeck(decks, orig);
	if(card!=-1){
		PushDeck(vector, decks, dest, vector[card]);
		if(decks[orig].top!=decks[orig].base)
			vector[decks[orig].top].state='V';
	}else
		printf("Deck %d is empty!",orig+1);
}

void ShuffleCards(card *vector, deck *decks,card *cards){
	int i,cont=0,k=0;
	Randomize(cards,-1,51);
	for(i = 0; i < 28; i++){
		if(k==7){
			cont++;
			k=cont;
		}
		PushDeck(vector,decks,k,cards[i]);
		k++;
	}
	for(i = 28; i < 52; i++)//the rest of the cards
		PushDeck(vector,decks,8,cards[i]);
	//passing 3 cards from reserve deck to discard deck
	for(i = 0; i < 3; i++)
		PassCard(vector,decks,8,7);
	for(i = 0; i < 8; i++){
		vector[decks[i].top].state='V';
		//ShowCard(vector[decks[i].top]);
		//PrintDeck(vector, decks,i);
	}
}

void MoveCard(card *vector, deck *decks){
	int i,j;
	printf("Indique origen -> destino: "); scanf("%d %d",&i,&j);
	if( decks[i].base < decks[i].top && i!=j && i>=0 && i < 7 && j>=0 && j < 7 && vector[decks[i].top].number == vector[decks[j].top].number - 1 && vector[decks[i].top].color != vector[decks[j].top].color)
		PassCard(vector,decks,i,j);
	else
		printf("No se puede hacer el movimiento\n");
}

void RandomizeDiscard(card *vector, deck *decks){
	int i;
	if(decks[8].top > decks[8].base){
		int n = decks[7].top-decks[7].base;
		//give back cards to reserve
		if(n>0)
			for(i = 0;i<n; i++)
				PassCard(vector,decks,7,8);
		Randomize(vector,decks[8].base,decks[8].top);
		//take new random cards
		n = decks[8].top-decks[8].base;
		for(i = 0; i < n, i < 3; i++)
			PassCard(vector,decks,8,7);
	}
	else
		printf("Reserve is Empty!\n");
}
