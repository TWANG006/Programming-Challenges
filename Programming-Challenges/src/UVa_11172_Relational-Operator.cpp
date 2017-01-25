/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2113
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>

int main()
{
	int t;
	long int a, b;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	scanf("%d", &t);
	while (t--)
	{
		scanf("%ld %ld", &a, &b);
		if (a > b) printf(">\n");
		else if (a < b) printf("<\n");
		else printf("=\n");
	}

	return 0;
}