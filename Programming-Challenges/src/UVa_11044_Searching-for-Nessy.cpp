/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=22&page=show_problem&problem=1985
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	int num_test_case = 0;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	scanf("%d", &num_test_case);

	int n, m;

	while (num_test_case--) {
		scanf("%d %d", &n, &m);
		printf("%d\n", (n / 3)*(m / 3));
	}

	return 0;
}