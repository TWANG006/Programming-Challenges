#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	int ts = 1;
	while (t--) {
		int n;
		scanf("%d", &n);
		
		int max_speed = -1;
		while (n--) {
			int speed;
			scanf("%d", &speed);
			max_speed = max(max_speed, speed);
		}

		printf("Case %d: %d\n", ts++, max_speed);
	}

	return 0;
}