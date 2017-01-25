/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=244&page=show_problem&problem=3431
*/

#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>

int main()
{
	int N, temp;
	int t =0, gt = 0;
	int caseNum = 1;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	while (scanf("%d", &N), N)
	{
		t = 0, gt = 0;
		while (N--)
		{
			scanf("%d", &temp);
			if (temp == 0) ++gt;
			else ++t;
		}
		printf("Case %d: %d\n", caseNum++, t - gt);
	}

	return 0;
}