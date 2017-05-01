#include <stdio.h>
#include "Decks.h"

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
}
