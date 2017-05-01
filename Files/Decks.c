#include <stdio.h>
#include "Decks.h"
/*
void InitDecks(int *base, int *top){
	int i;
	for(i = 0; i < 13; i++){
		base[i]=i*4;
		top[i]=base[i];
	}
}

int PopDeck(int *base, int *top, int deck){
	if(top[deck]==base[deck]){
		printf("Empty deck!");
		return -1;//
	}else{
		//int c=top[deck];
		top[deck]=top[deck]-1;
		return top[deck]+1;
	}
}

void ShiftRight(card *vector, int *base, int *top, int deck){
	int i,j;
	for(i=11;i>deck;i--){
		if(top[i] < base[i+1]){
			for(j=top[i];j>base[i];j--)
				vector[j+1]=vector[j];
			top[i]++;
			base[i]++;
		}
	}
}

void ShiftLeft(card *vector, int *base, int *top, int deck){
	int i,j;
	for(i=1;i<=deck;i++){
		if(base[i] > top[i-1]){
			for(j=base[i]+1;j<=top[i];j++)
				vector[j-1]=vector[j];
			top[i]--;
			base[i]--;
		}
	}
}

void PushDeck(card *vector,int *base,int *top,int deck,card c){
	int limit = (deck==12)?59:base[deck+1];
	if(top[deck]==limit)
		ShiftLeft(vector,base,top,deck);
	if(top[deck]==limit)
		ShiftRight(vector,base,top,deck);
	top[deck]++;
	vector[top[deck]]=c;	
}

void PrintDeck(card *vector,int base, int top){
	printf("Number\tColor\tState\n");
	int i;
	for(i=top; i>base; i--){
		printf("%d\t",vector[i].number);
		printf("%c\t",vector[i].color);
		printf("%c\n",vector[i].state);
	}
}*/

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
