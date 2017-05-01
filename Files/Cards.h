typedef struct card{
	int typ; //0 = Hearts, 1 = Spades, 2 = Diamonds, 3 = Clubs
	int number;
	char color; // B = Black, R = Red
	char state; // V = Visible, N = Not visible
}card;

void AddValueCards(card cards[52]);
void PrintCards(card cards[52]);
void Randomize(card cards[52]);
void Swap(card *A, card *B);
void FreeCard(card cards[52], int key);
void ShowCard(card c);
