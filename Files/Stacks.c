#include <stdio.h>
#include "Stacks.h"

void InitStacks(int n, stack *s){
	int i;
	for(i = 0; i < n; i++){
		s[i].end=-1;
		s[i].top=-1;
	}
}

void PopStack(card cards[52], stack *s){
	int act=s->top;
	int prev=cards[act].prev;
	if(act==-1)
		printf("Empty Stack!");
	else{
		s->top=prev;
		if(prev!=-1)
			cards[prev].next=-1;
		else
			printf("Stack is now empty!");
		cards[act].prev=-1;
	}
}

void PushStack(card cards[52], stack *s, int key){
	int act=s->top;
	cards[key].next=-1;
	if(act==-1)
		s->end=key;
	else 
		cards[act].next=key;
	cards[key].prev=act;		
	s->top=key;
}

void PrintStack(card cards[52], stack s){
	printf("Number\tColor\tState\n");
	int act = s.top;
	for(; act !=-1; act=cards[act].prev){
		printf("%d\t",cards[act].number);
		printf("%c\t",cards[act].color);
		printf("%c\n",cards[act].state);
	}
}
