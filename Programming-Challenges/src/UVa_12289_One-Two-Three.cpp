/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=244&page=show_problem&problem=3710
*/

#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int cases;
	char w[10];

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	scanf("%d", &cases);

	while (cases--)
	{
		scanf("%s", &w);

		// verify size
		int size = (int)strlen(w);
		if (size == 3)
		{
			if (w[0] == 'o') {
				if (w[1] == 'w'&&w[2] == 'o')
					printf("%d\n", 2);
				else
					printf("%d\n", 1);
			}
			else if (w[0] == 't') {
				if (w[1] == 'n'&&w[2] == 'e')
					printf("%d\n", 1);
				else
					printf("%d\n", 2);
			}
			else if (w[1] == 'n')
				printf("%d\n", 1);
			else
				printf("%d\n", 2);

		}
		else
		{
			printf("%d\n", 3);
		}
	}

	return 0;
}