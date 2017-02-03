#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<algorithm>
using namespace std;

int result(int a, int b)
{
	if (a > b)
		swap(a, b);
	if (a == 1) return b;
	else if (a == 2) return b / 4 * 4 + (b % 4 == 1 ? 2 : (b % 4 >= 2 ? 4 : 0));
	else return (a*b + 1) / 2;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b;

	while (scanf("%d %d", &a, &b), a || b)
	{
		printf("%d knights may be placed on a %d row %d column board.\n", result(a,b), a, b);
	}

	return 0;
}