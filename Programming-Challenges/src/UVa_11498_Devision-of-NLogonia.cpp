/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=26&page=show_problem&problem=2493
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>


int main()
{
	int K, N, M, X, Y;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	while (scanf("%d", &K), K)
	{
		scanf("%d %d", &N, &M);
		while (K--)
		{
			scanf("%d %d", &X, &Y);

			// comparison
			if (X == N || Y == M) printf("divisa\n");
			else if (X < N &&Y > M) printf("NO\n");
			else if (X > N&&Y > M) printf("NE\n");
			else if (X > N &&Y < M) printf("SE\n");
			else printf("SO\n");
		}
	}

	return 0;
}