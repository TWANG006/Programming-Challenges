#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;	// number of devices
	int m;	// number of operations
	int c;  // capacity of the fuse

	int tc = 1;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (scanf("%d %d %d", &n, &m, &c), n || m || c) {

		int max_c = -1;
		bitset<20> tog(0);
		vector<int> ci;
		while (n--) {
			int temp;
			scanf("%d", &temp);
			ci.push_back(temp);
		}
		int temp_max = 0;
		while (m--) {
			int temp;
			scanf("%d", &temp);
			int id = temp - 1;
			tog[id] = !tog[id];

			if (tog[id])
			{
				temp_max += ci[id];
			}
			else
				temp_max -= ci[id];
			max_c = max(temp_max, max_c);
		}
		printf("Sequence %d\n", tc++);
		max_c <= c ? printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", max_c) :
			printf("Fuse was blown.\n\n");
	}

	return 0;
}