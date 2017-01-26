#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>

int main()
{
	int t;	// test cases
	int ts = 1;
	
	scanf("%d", &t);
	while (t--) {
		int n;	// num of walls
		scanf("%d", &n);
		
		int highs = 0, lows = 0;
		int wall_1;
		scanf("%d", &wall_1);
		for (int i = 1; i < n; i++) {
			int wall;
			scanf("%d", &wall);
			if (wall > wall_1) highs++;
			else if (wall < wall_1)lows++;
			wall_1 = wall;
		}

		printf("Case %d: %d %d\n", ts++, highs, lows);
	}
	
	return 0;
}