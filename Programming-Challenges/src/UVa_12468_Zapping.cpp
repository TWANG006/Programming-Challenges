#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<algorithm>

using namespace std;

// id = (id+1)%n
// id = (id+n-1)%n
int main()
{
	int t, a, b;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	while (scanf("%d %d", &a, &b), a != -1 && b != -1) {
		if (a == b) {
			printf("%d\n", 0);
		}
		else if (a < b) {
			int temp = b - a - (a + 99 - b + 1);
			if (temp >= 0) 
				printf("%d\n", a + 99 - b + 1);
			else
				printf("%d\n", b - a);
		}
		else {
			int temp = a - b - (99 - a + b + 1);
			if (temp >= 0)
				printf("%d\n", 99 - a + b + 1);
			else
				printf("%d\n", a - b);
		}
	}
}