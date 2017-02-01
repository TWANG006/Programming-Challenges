#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	string s1, s2;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (getline(cin, s1)) {
		getline(cin, s2);

		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			if (islower(s1[i]))
				sum1 += s1[i] - 'a' + 1;
			else if (isupper(s1[i]))
				sum1 += s1[i] - 'A' + 1;
		}
		for (int i = 0; i < s2.size(); i++)
		{
			if (islower(s2[i]))
				sum2 += s2[i] - 'a' + 1;
			else if (isupper(s2[i]))
				sum2 += s2[i] - 'A' + 1;
		}
		sum1 = 1 + ((sum1 - 1) % 9);
		sum2 = 1 + ((sum2 - 1) % 9);

		if (sum1 ==0 && sum2 == 0)
		{
			printf("\n");
		}
		else {

			double result = 100.00*double(min(sum1, sum2)) / double(max(sum1, sum2));

			printf("%.2lf %%\n", result);
		}
	}

	return 0;
}

