/*
LCD Display

A friend of you has just bought a new computer. Until now, the most powerful computer he ever used
has been a pocket calculator. Now, looking at his new computer, he is a bit disappointed, because he
liked the LC-display of his calculator so much. So you decide to write a program that displays numbers
in an LC-display-like style on his computer.
Input
The input file contains several lines, one for each number to be displayed. Each line contains two
integers s, n (1 ¡Ü s ¡Ü 10, 0 ¡Ü n ¡Ü 99 999 999), where n is the number to be displayed and s is the size
in which it shall be displayed.
The input file will be terminated by a line containing two zeros. This line should not be processed.
Output
Output the numbers given in the input file in an LC-display-style using s ¡®-¡¯ signs for the horizontal
segments and s ¡®|¡¯ signs for the vertical ones. Each digit occupies exactly s + 2 columns and 2s + 3
rows. (Be sure to fill all the white space occupied by the digits with blanks, also for the last digit.)
There has to be exactly one column of blanks between two digits.
Output a blank line after each number. (You will find a sample of each digit in the sample output.)

Sample Input
2 12345
3 67890
0 0

Sample Output
      --  --         --
   |    |   | |   | |
   |    |   | |   | |
      --  --   --    --
   | |      |     |    |
   | |      |     |    |
      --  --         --
 --- ---   ---   ---   ---
|       | |   | |   | |   |
|       | |   | |   | |   |
|       | |   | |   | |   |
 ---       ---   ---
|   |   | |   |     | |   |
|   |   | |   |     | |   |
|   |   | |   |     | |   |
 ---       ---   ---   ---

*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int s = 0; 	// size of LCD digits 	
	char n[9];	// Vector to accept the input

	char LCDdigits[8][24][12];
	char LCDdigit[24][12];

	while (cin >> s)
	{
		cin >> n;

		if (s == 0 && strlen(n) == 1 && n[0] == '0')
			break;

		//1. Traverse all the input digits
		for (int i = 0; i < strlen(n); i++)
		{
			//2. Clear the contents in LCD digit
			for (int j = 0; j < 2 * s + 3; j++)
			{
				for (int k = 0; k < s + 2; k++)
				{
					LCDdigit[j][k] = ' ';
				}
			}
			
			//3. There are 10 cases in total
			switch (n[i])
			{
			case '0':
				for (int l = 1; l <= s; l++)
				{
					// - 
					LCDdigit[0][l] = '-';
					LCDdigit[2 * s + 2][l] = '-';
					// |
					LCDdigit[l][0] = '|';
					LCDdigit[l + s + 1][0] = '|';
					LCDdigit[l][s + 1] = '|';
					LCDdigit[l + s + 1][s + 1] = '|';
				}
				break;
			case '1':
				for (int l = 1; l <= s; l++)
				{
					// |
					LCDdigit[l][s + 1] = '|';
					LCDdigit[l + s + 1][s + 1] = '|';
				}
				break;
			case '2':
				for (int l = 1; l <= s; l++)
				{
					// - 
					LCDdigit[0][l] = '-';
					LCDdigit[s + 1][l] = '-';
					LCDdigit[2 * s + 2][l] = '-';
					// |
					LCDdigit[l + s + 1][0] = '|';
					LCDdigit[l][s + 1] = '|';
				}
				break;
			case '3':
				for (int l = 1; l <= s; l++)
				{
					// - 
					LCDdigit[0][l] = '-';
					LCDdigit[s + 1][l] = '-';
					LCDdigit[2 * s + 2][l] = '-';
					// |
					LCDdigit[l][s + 1] = '|';
					LCDdigit[l + s + 1][s + 1] = '|';
				}
				break;
			case '4':
				for (int l = 1; l <= s; l++)
				{
					// - 
					LCDdigit[s + 1][l] = '-';
					// |
					LCDdigit[l][0] = '|';
					LCDdigit[l][s + 1] = '|';
					LCDdigit[l + s + 1][s + 1] = '|';
				}
				break;
			case '5':
				for (int l = 1; l <= s; l++)
				{
					// - 
					LCDdigit[0][l] = '-';
					LCDdigit[s + 1][l] = '-';
					LCDdigit[2 * s + 2][l] = '-';
					// |
					LCDdigit[l][0] = '|';
					LCDdigit[l + s + 1][s + 1] = '|';
				}
				break;
			case '6':
				for (int l = 1; l <= s; l++)
				{
					// - 
					LCDdigit[0][l] = '-';
					LCDdigit[s + 1][l] = '-';
					LCDdigit[2 * s + 2][l] = '-';
					// |
					LCDdigit[l][0] = '|';
					LCDdigit[l + s + 1][0] = '|';
					LCDdigit[l + s + 1][s + 1] = '|';
				}
				break;
			case '7':
				for (int l = 1; l <= s; l++)
				{
					// - 
					LCDdigit[0][l] = '-';
					// |
					LCDdigit[l][s + 1] = '|';
					LCDdigit[l + s + 1][s + 1] = '|';
				}
				break;
			case '8':
				for (int l = 1; l <= s; l++)
				{
					// - 
					LCDdigit[0][l] = '-';
					LCDdigit[s + 1][l] = '-';
					LCDdigit[2 * s + 2][l] = '-';
					// |
					LCDdigit[l][0] = '|';
					LCDdigit[l + s + 1][0] = '|';
					LCDdigit[l][s + 1] = '|';
					LCDdigit[l + s + 1][s + 1] = '|';
				}
				break;
			case '9':
				for (int l = 1; l <= s; l++)
				{
					// - 
					LCDdigit[0][l] = '-';
					LCDdigit[s + 1][l] = '-';
					LCDdigit[2 * s + 2][l] = '-';
					// |
					LCDdigit[l][0] = '|';
					LCDdigit[l][s + 1] = '|';
					LCDdigit[l + s + 1][s + 1] = '|';
				}
				break;
			}

			//4. give LCDdigit to LCDdigits
			for (int j = 0; j < 2 * s + 3; j++)
			{
				for (int k = 0; k < s + 2; k++)
				{
					LCDdigits[i][j][k] = LCDdigit[j][k];
				}
			}
		}

		//5. Print the results

		for (int j = 0; j < 2 * s + 3; j++)
		{
			for (int i = 0; i < strlen(n); i++)
			{
				for (int k = 0; k < s + 2; k++)
				{
					cout << LCDdigits[i][j][k];
				}
				if (i < strlen(n) - 1)
					cout << ' ';
			}
			cout << endl;
		}
		cout << endl;		
	}
	
	return 0;
}