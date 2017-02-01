#define _CRT_SECURE_NO_DEPRECATE

#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	int tc = 1;

	ifstream in("input.txt", ios::in);
	cin.rdbuf(in.rdbuf());
	ofstream out("output.txt", ios::out | ios::trunc);
	cout.rdbuf(out.rdbuf());

	while (getline(cin, s))
	{
		if (s == "")
			continue;
		int n;
		cin >> n;
		cout << "Case " << tc++ << ":" << endl;
		while (n--)
		{
			int a, b;
			cin >> a >> b;
			int count[2] = { 0,0 };
			for (int i = min(a, b); i <= max(a, b); i++)
			{
				if (s[i] == '0') count[0]++;
				else count[1]++;
			}
			if (count[0] && count[1])
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
		}
		cin.ignore();
	}

	in.close();
	out.close();


	return 0;
}