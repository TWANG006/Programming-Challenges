#define _CRT_SECURE_NO_DEPRECATE

#include<string>
#include<sstream>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int t;
	cin >> t;

	char connector;
	cin.ignore();

	string s;
	while (t-- && getline(cin, s))
	{
		int m = 0, f = 0;

		for (auto it = s.cbegin(); it != s.cend(); it++)
		{
			if (*it == 'M') m++;
			else if (*it == 'F') f++;
		}

		(m == f && m != 1 && f != 1) ? printf("LOOP\n") : printf("NO LOOP\n");
	}

	return 0;
}