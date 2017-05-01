#include <stdio.h>
#include "Decks.h"

void InitDecks(int *base, int *top){
	int i;
	for(i = 0; i < 13; i++){
		base[i]=i*4;
		top[i]=base[i];
	}
}

int PopDeck(card *vector,int base, int *top){
	if(*top==base){
		printf("Empty deck!");
		return -1;//
	}else{
		int c=*top;
		*top=*top-1;
		return c;
	}
}

void GoRight(card *vector, int *base, int *top, int deck){
	int i,j;
	for(i=deck+1;i<13;i++){
		int bottom=(i==12)?59:base[i+1];
		if(top[i] < bottom){
			for(j=top[i];j>=base[i];j--)
				vector[j+1]=vector[j];
			top[i]++;
			base[i]++;
		}
	}
}

void GoLeft(card *vector, int *base, int *top, int deck){
	int i,j;
	for(i=deck;i>0;i--){
		if(base[i] > top[i-1]){
			for(j=base[i];j<=top[i];j++)
				vector[j-1]=vector[j];
			top[i]--;
			base[i]--;
		}
	}
}

void PushDeck(card *vector,int *base,int *top,int deck,card c){
	int i;
	if(top[deck]==base[deck+1] || (deck==12 && top[deck]==59)){
		GoLeft(vector,base,top,deck);
		GoRight(vector,base,top,deck);
	}
	vector[top[deck]]=c;
	top[deck]++;	
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
