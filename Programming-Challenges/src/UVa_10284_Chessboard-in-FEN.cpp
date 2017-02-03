#define	_CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

bool board[8][8];	// attacted or not
char cboard[8][8];	// characters 



int main()
{
	char fen[100];
	
	// get the input
	while (scanf("%s", &fen) != EOF)
	{
		int len = strlen(fen);
		int row = 0, col = 0;	// row & col id

		for (int i = 0; i < len; i++)
		{
			if (fen[i] == '/')
			{
				col = 0;
				row++;
			}
			else if (isdigit(fen[i]))
			{
				for (int i = 0; i < fen[i] - '0'; i++)
				{
					cboard[row][col] = '*';
					board[row][col] = true;
					col++;
				}
			}
			else
			{
				cboard[row][col] = fen[i];
				board[row][col] = false;
				col++;
			}
		}
	}

	return 0;
}