#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<unordered_map>
#include<array>
#include<algorithm>
using namespace std;

#define REP(i, a, b) for(int i=int(a); i<=int(b); i++)

struct Suit
{
	short suitCount = 0;
	bool isStopped = false;
};
struct Card
{
	char suit;
	char rank;
};

const unordered_map<char, short> suits_1 = {	// ids of each suit
	{ 'S',0 },
	{ 'H',1 },
	{ 'D',2 },
	{ 'C',3 }
};
const unordered_map<short, char> suits_2 = {	// ids of each suit
	{ 0,'S' },
	{ 1,'H' },
	{ 2,'D' },
	{ 3,'C' }
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (!feof(stdin))
	{
		Card card;
		array<Suit, 4> suitCounts;
		array<Card, 13> cards;
		short points = 0;
		short pointsno567 = 0;

		REP(i, 0, 12) {	// loop to get inputs
			scanf("%c%c ", &card.rank, &card.suit);
			cards[i] = card;	// save into card array
			suitCounts[suits_1.at(card.suit)].suitCount++;	// increase the suit count
		}

		// rules 1 to 4
		for (const auto &c : cards)
		{
			short id = suits_1.at(c.suit);
			switch (c.rank)
			{
			case 'A':
				points += 4;
				suitCounts[id].isStopped = true;
				break;
			case 'K':
				points += 3;
				if (suitCounts[id].suitCount > 1) suitCounts[id].isStopped = true;
				else if (suitCounts[id].suitCount <= 1) points -= 1;
				break;
			case 'Q':
				points += 2;
				if (suitCounts[id].suitCount > 2) suitCounts[id].isStopped = true;
				else if (suitCounts[id].suitCount <= 2) points -= 1;
				break;
			case 'J':
				points += 1;
				if (suitCounts[id].suitCount <= 3) points -= 1;
				break;
			}
		}

		// rules 5 to 7
		bool isAllstopped = true;
		for (const auto &s : suitCounts)
		{
			isAllstopped &= s.isStopped;
			switch (s.suitCount)
			{
			case 2:
				pointsno567 += 1; break;
			case 1:
				pointsno567 += 2; break;
			case 0:
				pointsno567 += 2; break;
			}
		}

		short totalPoints = points + pointsno567;

		if (totalPoints < 14) printf("PASS\n");
		else if (totalPoints >= 14) {
			if (points >= 16 && isAllstopped)
				printf("BID NO-TRUMP\n");
			else {
				short maxCount = -1;
				char suit;
				for (int i = 0; i < 4; i++) {
					if (suitCounts[i].suitCount > maxCount)
					{
						maxCount = suitCounts[i].suitCount;
						suit = suits_2.at(i);
					}
				}
				printf("BID %c\n", suit);
			}
		}
	}

	return 0;
}