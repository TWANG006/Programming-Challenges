/*
UVa_10963_The-Swallowing-Ground
*/

#define _CRT_SECURE_NO_DEPRECATE
#include<cstdio>

int main()
{
	int n, w;
	int y1, y2;

	scanf("%d", &n);

	while (n--) {
		scanf("%d", &w);
		
		bool flag = false;
		scanf("%d %d", &y1, &y2);
		int temp = y1 - y2;

		for (int i = 1; i < w; i++){
			scanf("%d %d", &y1, &y2);
			if (temp != (y1 - y2))
			{
				flag = true;
			}
		}
		
		flag ? printf("no\n") : printf("yes\n");
		if (n > 0)
			printf("\n");
	}

	return 0;
}