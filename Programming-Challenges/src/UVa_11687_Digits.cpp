#define _CRT_SECURE_NO_DEPRECATE

#include<string>
#include<iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	getline(cin, s);
	
	while (s != "END")
	{
		int count = 1;

		string x0 = s;
		string x1 = to_string(s.size());
		while (x1 != x0) {
			count++;
			x0 = x1;
			x1 = to_string(x0.size());
		}
		cout << count << endl;
		getline(cin, s);
	}

	return 0;
}