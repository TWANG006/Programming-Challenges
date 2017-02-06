#define	_CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

inline bool valid_move(int x) { return (x >= 0 && x < 8); }

bool board[8][8];	// attacted or not
char cboard[8][8];	// characters 

void rook(int x, int y) {
	int k = x;
	int l = y - 1;
	while (l >= 0) { // left
		if (cboard[k][l] == '*') {
			board[k][l] = false;
			l--;
		}
		else {
			break;
		}
	}

	k = x;
	l = y + 1;
	while (l<8) { // right
		if (cboard[k][l] == '*') {
			board[k][l] = false;
			l++;
		}
		else {
			break;
		}
	}

	k = x - 1;
	l = y;
	while (k >= 0) { // up
		if (cboard[k][l] == '*') {
			board[k][l] = false;
			k--;
		}
		else {
			break;
		}
	}

	k = x + 1;
	l = y;
	while (k<8) { // down
		if (cboard[k][l] == '*') {
			board[k][l] = false;
			k++;
		}
		else {
			break;
		}
	}
}

void knight(int x, int y) {
	if (valid_move(x - 1) && valid_move(y - 2))
		board[x - 1][y - 2] = false;
	if (valid_move(x - 1) && valid_move(y + 2))
		board[x - 1][y + 2] = false;
	if (valid_move(x + 1) && valid_move(y - 2))
		board[x + 1][y - 2] = false;
	if (valid_move(x + 1) && valid_move(y + 2))
		board[x + 1][y + 2] = false;
	if (valid_move(x - 2) && valid_move(y - 1))
		board[x - 2][y - 1] = false;
	if (valid_move(x - 2) && valid_move(y + 1))
		board[x - 2][y + 1] = false;
	if (valid_move(x + 2) && valid_move(y - 1))
		board[x + 2][y - 1] = false;
	if (valid_move(x + 2) && valid_move(y + 1))
		board[x + 2][y + 1] = false;
}

void bishop(int x, int y) {
	int k = x - 1;
	int l = y - 1;
	while (k >= 0 && l >= 0) { // Upper-left
		if (cboard[k][l] == '*') {
			board[k][l] = false;
			k--;
			l--;
		}
		else {
			break;
		}
	}

	k = x - 1;
	l = y + 1;
	while (k >= 0 && l<8) { // Upper-right
		if (cboard[k][l] == '*') {
			board[k][l] = false;
			k--;
			l++;
		}
		else {
			break;
		}
	}

	k = x + 1;
	l = y - 1;
	while (k<8 && l >= 0) { // Down-left
		if (cboard[k][l] == '*') {
			board[k][l] = false;
			k++;
			l--;
		}
		else {
			break;
		}
	}

	k = x + 1;
	l = y + 1;
	while (k<8 && l<8) { // Down-right
		if (cboard[k][l] == '*') {
			board[k][l] = false;
			k++;
			l++;
		}
		else {
			break;
		}
	}
}

void queen(int x, int y) {
	rook(x, y);
	bishop(x, y);
}

void king(int x, int y) {
	if (valid_move(x - 1) && valid_move(y - 1))
		board[x - 1][y - 1] = false;
	if (valid_move(x - 1) && valid_move(y))
		board[x - 1][y] = false;
	if (valid_move(x - 1) && valid_move(y + 1))
		board[x - 1][y + 1] = false;
	if (valid_move(x) && valid_move(y - 1))
		board[x][y - 1] = false;
	if (valid_move(x) && valid_move(y + 1))
		board[x][y + 1] = false;
	if (valid_move(x + 1) && valid_move(y - 1))
		board[x + 1][y - 1] = false;
	if (valid_move(x + 1) && valid_move(y))
		board[x + 1][y] = false;
	if (valid_move(x + 1) && valid_move(y + 1))
		board[x + 1][y + 1] = false;
}

void pawn(int x, int y, bool color) {
	// true for black
	// false for white
	if (color) {
		if (valid_move(x + 1) && valid_move(y - 1))
			board[x + 1][y - 1] = false;
		if (valid_move(x + 1) && valid_move(y + 1))
			board[x + 1][y + 1] = false;
	}
	else {
		if (valid_move(x - 1) && valid_move(y - 1))
			board[x - 1][y - 1] = false;
		if (valid_move(x - 1) && valid_move(y + 1))
			board[x - 1][y + 1] = false;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char fen[1000];

	// get the input
	while (scanf("%s", &fen) != EOF)
	{
		int len = 0;
		int row = 0, col = 0;	// row & col id

		while (fen[len]) {
			if (fen[len] == '/')
			{
				col = 0;
				row++;
			}
			else if (isdigit(fen[len]))
			{
				for (int j = 0; j < fen[len] - '0'; j++)
				{
					cboard[row][col] = '*';
					board[row][col] = true;
					col++;
				}
			}
			else
			{
				cboard[row][col] = fen[len];
				board[row][col] = false;
				col++;
			}
			len++;
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (cboard[i][j] == 'p') pawn(i, j, true);
				else if (cboard[i][j] == 'P') pawn(i, j, false);
				else if (cboard[i][j] == 'n' || cboard[i][j] == 'N') knight(i, j);
				else if (cboard[i][j] == 'b' || cboard[i][j] == 'B') bishop(i, j);
				else if (cboard[i][j] == 'r' || cboard[i][j] == 'R') rook(i, j);
				else if (cboard[i][j] == 'q' || cboard[i][j] == 'Q') queen(i, j);
				else if (cboard[i][j] == 'k' || cboard[i][j] == 'K') king(i, j);
			}
		}

		int count = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j])
					count++;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}