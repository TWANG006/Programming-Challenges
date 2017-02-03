#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	short princess[3], prince[2];

	while (scanf("%d %d %d %d %d", &princess[0], &princess[1], &princess[2],
		&prince[0], &prince[1]),
		princess[0] || princess[1] || princess[2] || prince[0] || prince[1])
	{
		sort(princess, princess + 3);
		if (prince[0] > prince[1])
			swap(prince[0], prince[1]);

		int temp = 0;

		// each one at least greater than 2 of the princess
		if (prince[0] > princess[1] && prince[0] < princess[2])
		{
			temp = princess[1] + 1;
			if (temp == princess[2] || temp == prince[0] || temp == prince[1]) temp += 1;
			if (temp == princess[2] || temp == prince[0] || temp == prince[1]) temp += 1;
			if (temp == princess[2] || temp == prince[0] || temp == prince[1]) temp += 1;
		}
		else if (prince[1] > princess[2] && prince[0] < princess[1])
		{
			temp = princess[2] + 1;
			if (temp == prince[1]) temp += 1;
		}
		else if (prince[0] > princess[2])
		{
			temp = 1;
			if (temp == princess[0]) temp += 1;
			if (temp == princess[1]) temp += 1;
			if (temp == princess[2]) temp += 1;
			if (temp == prince[0]) temp += 1;
			if (temp == prince[1]) temp += 1;
		}

		(temp == 0 || temp > 52) ? printf("%d\n", -1) : printf("%d\n", temp);
	}

	return 0;
}