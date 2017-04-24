#include<stdio.h>
#include "Cards.h"

void AddValueCards(card cards[52]){
    int i, j, k = 0;//, typCont = 0;
    for(j = 0; j < 4; j++){
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
                //no mames we!
            }
            cards[k].number = i;
            cards[k].state = 'N';
            cards[k].next=-1;
            cards[k].prev=-1;
            k++;
        }
    }
}
void PrintCards(card cards[52]){
	printf("Number\tColor\tState\n");
	int n = 0;
	for(; n < 52; n++){
		printf("%d\t",cards[n].number);
		printf("%c\t",cards[n].color);
		printf("%c\n",cards[n].state);
	}
}

void Swap(card *A, card *B) {
    card temp = *A;
    *A = *B;
    *B = temp;
}

void Randomize(card cards[52]) {
    srand(time(NULL));
    int i;
    for(i = 51; i > 0; i--) {
        int j = rand() % (i+1);
        Swap(&cards[i], &cards[j]);
    }
}

void FreeCard(card cards[52], int key){
	cards[key].next=-1;
	cards[key].prev=-1;
}

void ShowCard(card c){
	printf("---------\n");
	printf("|%d\t|\n",c.number);
	printf("|\t|\n");
	printf("|\t|\n");
	printf("|\t|\n");
	printf("---------\n");
}
