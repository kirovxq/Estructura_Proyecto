#include <stdio.h>
#include "Stacks.h"

void main(){
	card cards[52];
	AddValueCards(cards);
	Randomize(cards);
	stack stacks[1];
	InitStacks(1, stacks);
	PushStack(cards, &stacks[0], 3);
	PushStack(cards, &stacks[0], 4);
	PushStack(cards, &stacks[0], 5);
	//PrintCards(cards);
	ShowCard(cards[35]);
	PrintStack(cards, stacks[0]);
}
