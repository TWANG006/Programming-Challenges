/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1055
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>

int main()
{
	int duration, dp_record;
	double down, loan, dp[101];

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	// Outter loop for cases
	while (scanf("%d %lf %lf %d",
		&duration, &down, &loan, &dp_record), duration >= 0) {	// Get the inputs

		int m; double p;
		while (dp_record--) {
			scanf("%d %lf", &m, &p);
			for (int i = m; i < 101; i++)	// Put all needed dp values into an array
				dp[i] = p;
		}

		int result = 0;
		double worth = (loan + down)*(1.0 - dp[0]);
		double monthly = loan / duration;
		double owes = loan;

		while (owes > worth)
		{
			result++;
			owes -= monthly;
			worth = worth*(1.0 - dp[result]);
		}

		if (result != 1)
			printf("%d months\n", result);
		else
			printf("%d month\n", result);
	}

	return 0;
}
