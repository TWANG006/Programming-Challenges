#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>

int main()
{
	long n;

	while (scanf("%d", &n), n) {
		printf("%d\n", 1 + (n - 1) % 9);
	}

	return 0;
}