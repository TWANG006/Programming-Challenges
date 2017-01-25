/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=278&page=show_problem&problem=3794
*/
#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>

int main()
{
	int n;
	int l, w, h;
	int caseNum = 1;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d %d", &l, &w, &h);
		if (l <= 20 && w <= 20 && h <= 20)
			printf("Case %d: good\n", caseNum++);
		else
			printf("Case %d: bad\n", caseNum++);
	}

	return 0;
}