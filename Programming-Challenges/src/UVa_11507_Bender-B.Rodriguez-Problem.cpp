#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>

using namespace std;

int main()
{
	long l;
	char input[3], direct[3];
	direct[2] = '\0';

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (scanf("%ld", &l), l)
	{
		direct[0] = '+', direct[1] = 'x';

		for (int i = l - 1; i >= 1; i--) {
			scanf("%s", &input);

			if (input[0] == 'N')
			{
				continue;
			}

			if (direct[1] == 'x')
			{
				direct[1] = input[1];
				direct[0] = (input[0] == direct[0]) ? '+' : '-';
			}
			else if (input[1] == 'y')
			{
				if (direct[1] == 'y')
				{
					direct[1] = 'x';
					direct[0] = (input[0] == direct[0]) ? '-' : '+';
				}
			}
			else
			{
				if (direct[1] == 'z')
				{
					direct[1] = 'x';
					direct[0] = (input[0] == direct[0]) ? '-' : '+';
				}
			}
		}
		printf("%s\n", direct);
	}

	return 0;
}