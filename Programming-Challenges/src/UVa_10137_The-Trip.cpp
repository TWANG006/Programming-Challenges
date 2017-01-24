/*

The Trip

A number of students are members of a club that travels annually to exotic locations. Their destinations
in the past have included Indianapolis, Phoenix, Nashville, Philadelphia, San Jose, and Atlanta. This
spring they are planning a trip to Eindhoven.
The group agrees in advance to share expenses equally, but it is not practical to have them share
every expense as it occurs. So individuals in the group pay for particular things, like meals, hotels, taxi
rides, plane tickets, etc. After the trip, each student¡¯s expenses are tallied and money is exchanged so
that the net cost to each is the same, to within one cent. In the past, this money exchange has been
tedious and time consuming. Your job is to compute, from a list of expenses, the minimum amount of
money that must change hands in order to equalize (within a cent) all the students¡¯ costs.
Input
Standard input will contain the information for several trips. The information for each trip consists of
a line containing a positive integer, n, the number of students on the trip, followed by n lines of input,
each containing the amount, in dollars and cents, spent by a student. There are no more than 1000
students and no student spent more than $10,000.00. A single line containing 0 follows the information
for the last trip.
Output
For each trip, output a line stating the total amount of money, in dollars and cents, that must be
exchanged to equalize the students¡¯ costs.
Sample Input
3
10.00
20.00
30.00
4
15.00
15.01
3.00
3.01
0
Sample Output
$10.00
$11.99

*/

#include <iostream>
#include <vector>

using namespace std;

double balancedMoney(const vector<double>&dollars)
{
	double mean = 0.0;
	double in = 0.0;
	double out = 0.0;

	// Compute the mean
	for (const auto& val : dollars)
	{
		mean += val;
	}
	mean /= double(dollars.size());

	// Get the results
	for (const auto& val : dollars)
	{
		double delta = val - mean;

		if (delta < 1e-6f)
		{
			in += -(int(delta)) / 100.0;
		}			
		else
		{
			out += int(delta) / 100.0;
		}
	}
	return in > out ? in : out;
}

int main()
{
	int n = 0;	// number of students
	
	while (cin >> n)
	{
		if (n == 0)
			break;

		vector<double> dollars(n, 0);	// vector of results

		//1. Get the inputs
		for (int i = 0; i < n; i++)
		{
			cin >> dollars[i];
			dollars[i] = dollars[i] * 100.0;
		}

		//2. Balance the money
		double balancedAmount = balancedMoney(dollars);

		//3. Output
		printf("$%.2f\n", balancedAmount);
		
	}

	return 0;
}