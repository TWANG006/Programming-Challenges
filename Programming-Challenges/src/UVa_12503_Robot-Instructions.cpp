#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>

using namespace std;

int instructions[101];

int main()
{
	int t;
	char s[20];

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);

	while (t--) {		
		int p = 0;
		int n;
		int step = -1;

		scanf("%d", &n);
		
		for (int i = 0; i < n; i++)
		{
			scanf("%s", &s);

			if (s[0] == 'L') p += instructions[i] = -1;
			else if (s[0] == 'R') p += instructions[i] = 1;
			else {
				scanf("%*s %d", &step);
				p += instructions[i] = instructions[step - 1];
			}				
		}

		printf("%d\n", p);
	}
	
	return 0;
}