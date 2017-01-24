/*
You have been given the job of forming the quiz teams for the next ‘MCA CPCI Quiz Championship’.
There are 2 ∗ N students interested to participate and you have to form N teams, each team consisting
of two members. Since the members have to practice together, all the students want their members
house as near as possible. Let x1 be the distance between the houses of group 1, x2 be the distance
between the houses of group 2 and so on. You have to make sure the summation (x1+x2+x3+. . .+xn)
is minimized.

Input
There will be many cases in the input file. Each case starts with an integer N (N ≤ 8). The next 2 ∗ N
lines will given the information of the students. Each line starts with the students name, followed by
the x coordinate and then the y coordinate. Both x, y are integers in the range 0 to 1000. Students
name will consist of lowercase letters only and the length will be at most 20.
Input is terminated by a case where N is equal to 0.

Output
For each case, output the case number followed by the summation of the distances, rounded to 2 decimal
places. Follow the sample for exact format.

Sample Input
5
sohel 10 10
mahmud 20 10
sanny 5 5
prince 1 1
per 120 3
mf 6 6
kugel 50 60
joey 3 24
limon 6 9
manzoor 0 0
1
derek 9 9
jimmy 10 10
0

Sample Output
Case 1: 118.40
Case 2: 1.41
*/

#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

// Globals
int N, target;
double dist[20][20], memo[1 << 16];

double matching(int bitmask)
{
	if (memo[bitmask] > -1)		// since the results are already in
		return memo[bitmask];
	if (bitmask == target)		// since all students are paired already, cost= 0;
		return memo[bitmask] = 0;

	double ans = 2000000000.0;	// Initialize to a large value
	int s1, s2;
	for (s1 = 0; s1 < 2 * N; s1++)
		if (!(bitmask & (1 << s1)))
			break;
	for (s2 = s1 + 1; s2 < 2 * N; s2++)
		if (!(bitmask & (1 << s2)))
		{
			ans = min(ans,
				dist[s1][s2] + matching(bitmask | (1 << s1) | (1 << s2)));
		}
	return memo[bitmask] = ans;
}

int main()
{
	int caseNum = 1, x[20], y[20];

	freopen("input.txt", "r", stdin);

	// Parse the input
	while (scanf("%d", &N), N) {
		for (int i = 0; i < 2 * N; i++) {
			scanf("%*s %d %d", &x[i], &y[i]); // Get the information line by line			
		}
		for (int i = 0; i < 2 * N - 1; i++) {
			for (int j = i + 1; j < 2 * N; j++) {	// build the pairwise dist matrix
				dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
			}
		}

		// Apply the DP algorithm with bitmask states
		target = (1 << (2 * N)) - 1;
		for (int i = 0; i < (1 << 16); i++) memo[i] = -1.0;	// initialize the memo to -1

		// Output: case number + sum of distance
		printf("Case %d: %.2lf\n", caseNum++, matching(0));
	}
	return 0;
}
