#include <stdio.h>
#include "Decks.h"

void InitDecks(int n, deck *s){
	int i;
	for(i = 0; i < n; i++){
		s[i].end=-1;
		s[i].top=-1;
	}
}

int PopDeck(card cards[52], deck *s){
	int act=s->top;
	int prev=cards[act].prev;
	if(act==-1)
		printf("Empty Stack!");
		return -1;
	else{
		s->top=prev;
		if(prev!=-1)
			cards[prev].next=-1;
		else
			printf("Stack is now empty!");
		cards[act].prev=-1;
		return act;
	}
}

void PushDeck(card cards[52], deck *s, int key){
	int act=s->top;
	cards[key].next=-1;
	if(act==-1)
		s->end=key;
	else 
		cards[act].next=key;
	cards[key].prev=act;		
	s->top=key;
}

void PrintDeck(card cards[52], deck s){
	printf("Number\tColor\tState\n");
	int act = s.top;
	for(; act !=-1; act=cards[act].prev){
		printf("%d\t",cards[act].number);
		printf("%c\t",cards[act].color);
		printf("%c\n",cards[act].state);
	}
}
