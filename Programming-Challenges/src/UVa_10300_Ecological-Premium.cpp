/*
UVa_10300_Ecological-Premium
*/

#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>

int main()
{
	int n, f;
	long int area, ef;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &f);
		long int sum = 0;
		while (f--) {
			scanf("%ld %*ld %ld", &area, &ef);
			sum += area * ef;
		}

		printf("%ld\n", sum);
	}

	return 0;
}