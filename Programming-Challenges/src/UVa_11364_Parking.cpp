/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=25&page=show_problem&problem=2349
*/
#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int t, n, x;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d", &n);
		int l = 100;
		int r = -1;
		while (n--) {
			scanf("%d", &x);
			l = min(l, x);
			r = max(r, x);
		}
		printf("%d\n", 2 * (r - l));
	}

	return 0;
}