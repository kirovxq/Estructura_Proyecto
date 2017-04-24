#include <stdio.h>
#include "Cards.h"
void main(){
	card cards[52];
	AddValueCards(cards);
	Randomize(cards);
	PrintCards(cards);
}

/*

typedef struct stack{
	int nCards;
	card *first;
	card *last;
}stack;

void initStack(stack *s){
	s->first=NULL;
	s->last=NULL;
	s->nCards=0;
}

void push(stack *s, card *c){
	if(s->first==NULL){
        s->first=c;
        s->last=c;
    }else{
        c->prev=s->last;
        s->last->next=c;
        s->last=c;
    }
    s->nCards++;
}

card *pop(stack *s){
	card *c;
	if(s->last!=NULL){
	  c=s->last;
	  s->last=s->last->prev;
	  //s->last->next=NULL;
	  s->nCards--;
	}
	return c;
}
*/
