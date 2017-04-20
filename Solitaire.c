#include<stdio.h>
#include<stdlib.h>

typedef struct card{
	int type;
	int number;
	char color;
	char state;
	struct card *next;
	struct card *prev;
}card;

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

void initCards(card *cards){
	int i,j;
	for(i=0;i<13;i++){
		for(j=0;j<4;j++){
			cards[j*13+i].type=j;
			cards[j*13+i].number=i;
			//cards[j*13+i].color='r'
			cards[j*13+i].state=0;
			cards[j*13+i].prev=NULL;
			cards[j*13+i].next=NULL;
		}	
	}
}

void main(){
	stack hands[7];
	card cards[52];
	int i;
	initCards(cards);
	for(i=0;i<7;i++)initStack(&hands[i]);
}
