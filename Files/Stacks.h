#include "Cards.h"

typedef struct stack{
	int end;
	int top;
}stack;

void InitStacks(int n, stack *s);
void PushStack(card cards[52], stack *s, int key);
void PopStack(card cards[52], stack *s);
void PrintStack(card cards[52], stack s);
