/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1055
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>

int main()
{
	int duration, dp_record;
	double down, loan;

	while (scanf("%d %lf %lf %d", 
		&duration, &down, &loan, &dp_record), duration >= 0)
	{
		double owes = loan, worth = loan;
		int result_month = 0;
		int month = 0;

		// Begin the iteration on duration
		while(duration--)
		{	
			double current_dp;
			int current_month = 0;

			if (month == 0)
			{
				scanf("%*d %lf", &current_month, &current_dp);
				worth -= worth*(1 - current_dp);
			}
			else
			{

			}

			owes -= down;	// down the owes		
			

			result_month++;
			month++;

			if (owes < worth)
				break;
								
		}

		// Output each case
		result_month > 1 ? printf("%d months\n", result_month) : printf("%d month\n", result_month);
	}

	return 0;
}
