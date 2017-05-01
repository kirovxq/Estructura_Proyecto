#include <stdio.h>
#include "Decks.h"

void InitDecks(deck *decks){
	int i;
	for(i = 0; i < 13; i++){
		decks[i].base=i*4;
		decks[i].top=decks[i].base;
	}
}

int PopDeck(deck *decks, int key){
	if(decks[key].top==decks[key].base){
		printf("Empty deck!");
		return -1;//
	}else{
		//int c=top[deck];
		decks[key].top--;
		return decks[key].top+1;
	}
}

void ShiftRight(card *vector, deck *decks, int key){
	int i,j;
	for(i=11;i>key;i--){
		if(decks[i].top < decks[i+1].base){
			for(j=decks[i].top;j>decks[i].base;j--)
				vector[j+1]=vector[j];
			decks[i].top++;
			decks[i].base++;
		}
	}
}

void ShiftLeft(card *vector, deck *decks, int key){
	int i,j;
	for(i=1;i<=key;i++){
		if(decks[i].base > decks[i-1].top){
			for(j=decks[i].base+1;j<=decks[i].top;j++)
				vector[j-1]=vector[j];
			decks[i].top--;
			decks[i].base--;
		}
	}
}

void PushDeck(card *vector, deck *decks, int key,card c){
	int limit = (key==12)?59:decks[key+1].base;
	if(decks[key].top==limit)
		ShiftLeft(vector,decks,key);
	if(decks[key].top==limit)
		ShiftRight(vector,decks,key);
	decks[key].top++;
	vector[decks[key].top]=c;	
}

void PrintDeck(card *vector,deck *decks, int key){
	printf("*******************\nDeck: %d",key+1);
	printf("\n*******************\n");
	printf("Number\tColor\tState\n");
	int i;
	for(i=decks[key].top; i>decks[key].base; i--){
		printf("%d\t",vector[i].number);
		printf("%c\t",vector[i].color);
		printf("%c\n",vector[i].state);
	}
}
