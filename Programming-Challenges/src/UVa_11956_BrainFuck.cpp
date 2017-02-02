#define _CRT_SECURE_NO_DEPRECATE

#include<iomanip>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;
	int tc = 1;
	cin.ignore();
	while (t--)
	{
		vector<unsigned int> bytes(100, 0);	// 100 bytes;
		string commands;			// commands
		long ptr = 0;				// the pointer pos
	
		getline(cin, commands);

		for (auto it = commands.cbegin(); it != commands.cend(); it++)
		{
			if (*it == '.') continue;
			else if (*it == '+') bytes[ptr] = (bytes[ptr] + 1) % 256;
			else if (*it == '-') bytes[ptr] = (bytes[ptr] + 255) % 256;
			else if (*it == '>') ptr = (ptr + 1) % 100;
			else if (*it == '<') ptr = (ptr + 99) % 100;
		}

		cout << "Case " << dec << tc++ << ": ";
		string sep = "";
		for (auto it = bytes.cbegin(); it != bytes.cend(); it++)
		{
			cout << sep;
			sep = " ";
			cout << setfill('0') << setw(2) << uppercase << hex << *it;
		}
		cout << endl;
	}
	
	return 0;
}