/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2542
*/

#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	int t;
	long int n;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	scanf("%d", &t);

	while (t--)
	{
		scanf("%ld", &n);
		long int temp = 36962 + 315 * n;
		printf("%ld\n", std::abs(temp / 10 % 10));
	}

	return 0;
}