/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=279&page=show_problem&problem=3834
*/

#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	int T;
	long int sum = 0;
	long int temp;
	char op[10];
	
	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	scanf("%d", &T);

	while (T--) {
		scanf("%s", &op);

		if (!strcmp(op, "donate")) {
			scanf("%ld", &temp);
			sum += temp;
		}
		else if (!strcmp(op, "report"))
		{
			printf("%ld\n", sum);
		}
	}

	return 0;
}