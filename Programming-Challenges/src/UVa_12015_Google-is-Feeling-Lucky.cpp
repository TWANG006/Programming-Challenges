#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{	
	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	char url[10][25];
	int rel[25];

	int t;
	int tc = 1;

	scanf("%d", &t);

	while (t--) {
		int max_rel = -1;
		for (int i = 0; i < 10; i++) {
			scanf("%s %d", &url[i], &rel[i]);
			max_rel = max(max_rel, rel[i]);
		}

		printf("Case #%d:\n", tc++);
		for (int i = 0; i < 10; i++) {
			if (rel[i] == max_rel)
				printf("%s\n", url[i]);
		}
	}
	
	return 0;
}