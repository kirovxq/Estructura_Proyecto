#include <stdio.h>

typedef struct card{
	int typ; //0 = Hearts, 1 = Spades, 2 = Diamonds, 3 = Clubs
	int number;
	char color; // B = Black, R = Red
	char state; // V = Visible, N = Not visible
	struct card *next;
	struct card *prev;
}card;

void AddValueCards(card cards[52]){
    int i = 0, j = 0, k = 0, typCont = 0;
    for(; j < 4; j++){
        if(i == 13)
            i = 1;
        for(i = 1; i <= 13; i++){
            switch(j){
                case 0:
                case 2: cards[k].color = 'B';
                        break;
                case 1:
                case 3: cards[k].color = 'R';
                        break;
                default: printf("Wtf this just happened?\n");
            }
            cards[k].number = i;
            cards[k].state = 'N';
            k++;
        }
    }
}

void main(){
    card cards[52];
    AddValueCards(cards);
    printf("Number\tColor\tState\n");
    int n = 0;
    for(; n < 52; n++){
        printf("%d\t",cards[n].number);
        printf("%c\t",cards[n].color);
        printf("%c\n",cards[n].state);
    }
}

/*
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
*/
