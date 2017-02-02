#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int heights[10010];

	int a, c;	// height, length

	while (scanf("%d %d", &a, &c), a)
	{
		int count = 0;
		scanf("%d", &heights[0]);
		count += a - heights[0];

		for (int i = 1; i < c; i++)
		{
			scanf("%d", &heights[i]);
			int temp = heights[i - 1] - heights[i];
			if (temp > 0)
				count += temp;
		}
		printf("%d\n", count);
	}

	return 0;
}