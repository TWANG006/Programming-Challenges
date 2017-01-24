/*
Have you ever played Minesweeper? It¡¯s a cute little game which comes within a certain Operating
System which name we can¡¯t really remember. Well, the goal of the game is to find where are all the
mines within a M ¡Á N field. To help you, the game shows a number in a square which tells you how
many mines there are adjacent to that square. For instance, supose the following 4 ¡Á 4 field with 2
mines (which are represented by an ¡®*¡¯ character):
*...
....
.*..
....
If we would represent the same field placing the hint numbers described above, we would end up
with:
*100
2210
1*10
1110
As you may have already noticed, each square may have at most 8 adjacent squares.
Input
The input will consist of an arbitrary number of fields. The first line of each field contains two integers
n and m (0 < n, m ¡Ü 100) which stands for the number of lines and columns of the field respectively.
The next n lines contains exactly m characters and represent the field.
Each safe square is represented by an ¡®.¡¯ character (without the quotes) and each mine square
is represented by an ¡®*¡¯ character (also without the quotes). The first field line where n = m = 0
represents the end of input and should not be processed.
Output
For each field, you must print the following message in a line alone:
Field #x:
Where x stands for the number of the field (starting from 1). The next n lines should contain the
field with the ¡®.¡¯ characters replaced by the number of adjacent mines to that square. There must be
an empty line between field outputs.

Sample Input

4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0

Sample Output

Field #1:
*100
2210
1*10
1110

Field #2:
**100
33200
1*100

*/

#include <iostream>
#include <vector>

using namespace std;

// Rest all element of count[][] to 0's
void clearCount(vector<vector<int>>& v_count)
{
	for (auto&sub : v_count)
	{
		fill(sub.begin(), sub.end(), 0);
	}
}

// Count the number near the mine
void countNumbers(vector<vector<int>>& v_count, int y, int x, int m, int n)
{
	v_count[y][x] = -1;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (y + i >= 0 && y + i < m && x + j >= 0 && x + j < n && v_count[y + i][x + j] != -1)
			{
				v_count[y + i][x + j]++;
			}
		}
	}
}

void printCounts(const vector<vector<int>>& v_count, int numField, int m, int n)
{
	cout << "Field #" << numField << ":" << endl;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v_count[i][j] == -1)
				cout << "*";
			else
				cout << v_count[i][j];
		}

		cout << endl;
	}
}


int main()
{
	int m, n;				// rows & cols
	int numField = 1;		// Number of fields
	char rowChar[100 + 1];	// char's along one row + '\0'

	// count[100][100] to save the counts
	vector<vector<int>> count(100, vector<int>(100, 0));

	// Get inputs
	while (cin >> m >> n)
	{
		//1. m=n=0
		if (m == 0 && n == 0)
		{
			break;
		}

		clearCount(count);

		//2. Get patterns from input
		for (int i = 0; i < m; i++)
		{		
			cin >> rowChar;

			for (int j = 0; j < n; j++)
			{
				//3. Set the mine&count
				if (rowChar[j] == '*')
				{
					countNumbers(count, i, j, m, n);
				}
			}
		}

		//4. Print the results
		if (numField > 1)
			cout << endl;

		printCounts(count, numField, m, n);

		//5. Increase the number of fields
		numField++;
	}

	return 0;
}