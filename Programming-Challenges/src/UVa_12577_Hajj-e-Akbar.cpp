/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=441&page=show_problem&problem=4022
*/
#define _CRT_SECURE_NO_DEPRECATE
#include<cstring>
#include<cstdio>
using namespace std;

int main()
{
	const char Umrah[] = "Hajj-e-Asghar";
	const char Hajj[] = "Hajj-e-Akbar";
	char c[8];
	int caseNum = 1;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	while (scanf("%s", c), c[0] != '*')
	{
		if (!strcmp("Hajj", c))
			printf("Case %d: %s\n", caseNum++, Hajj);
		else if (!strcmp("Umrah", c))
		{
			printf("Case %d: %s\n", caseNum++, Umrah);
		}
	}
}