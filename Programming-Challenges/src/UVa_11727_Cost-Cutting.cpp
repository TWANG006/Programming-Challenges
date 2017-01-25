/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=117&page=show_problem&problem=2827
*/

#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int T;
	int employee[3];
	int caseNum = 1;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	scanf("%d", &T);

	while (T--)
	{
		for (int i = 0; i < 3; ++i)
		{
			scanf("%d", &employee[i]);
		}

		sort(employee, employee + 3);

		printf("Case %d: %d\n", caseNum++, employee[1]);
	}

	return 0;
}