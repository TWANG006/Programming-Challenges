#define _CRT_SECURE_NO_DEPRECATE

#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int l;

	while (cin >> l, l)
	{
		cin.ignore();

		string s;
		getline(cin, s);

		long minDist = l;					// min distance
		long lastD = -l, lastR = -l;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'Z')
			{
				minDist = 0;
				break;
			}
			else if (s[i] == 'R')
			{
				minDist = min(minDist, i - lastD);
				lastR = i;
			}
			else if (s[i] == 'D')
			{
				minDist = min(minDist, i - lastR);
				lastD = i;
			}
		}

		cout << minDist << endl;
		
	}

	return 0;
}