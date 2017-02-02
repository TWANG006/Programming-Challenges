#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<array>
#include<unordered_map>
using namespace std;

const unordered_map<char, int> values = {
	{ '2',2 },
	{ '3',3 },
	{ '4',4 },
	{ '5',5 },
	{ '6',6 },
	{ '7',7 },
	{ '8',8 },
	{ '9',9 },
	{ 'T',10 },
	{ 'J',10 },
	{ 'Q',10 },
	{ 'K',10 },
	{ 'A',10 }
};

struct Card
{
	char suit, rank;
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d\n", &t);

	int tc = 1;
	while (t--)
	{
		Card card;
		array<Card, 52> cards;
		for (int i = 0; i < 52; i++)
		{
			scanf("%c%c ", &card.rank, &card.suit);
			cards[i].rank = card.rank;
			cards[i].suit = card.suit;
		}

		int y = 0;
		int top_id = 26;
		int n = 3;

		while (n--) {
			// Take the top card
			int x = values.at(cards[top_id].rank);
			y += x;
			top_id = top_id - 1 - (10 - x);
		}
		if (y >= top_id)
			y = y - top_id + 25;
		printf("Case %d: %c%c\n", tc++, cards[y].rank, cards[y].suit);
	}

	return 0;
}