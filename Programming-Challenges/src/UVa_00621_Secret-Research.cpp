/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=8&page=show_problem&problem=562
*/

#include<string>
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream in("input.txt", ios::in);
	cin.rdbuf(in.rdbuf());
	ofstream out("output_mine.txt", ios::out | ios::trunc);
	cout.rdbuf(out.rdbuf());

	long n;
	string s;
	cin >> n;

	while (n--) {
		cin >> s;
		int len = (int)s.length();
		if (s == "1" || s == "4" || s == "78") cout << "+" << endl;
		else if (s.substr(len - 2) == "35") cout << "-" << endl;
		else if (s[0] == '9'&&s[len - 1] == '4') cout << "*" << endl;
		else cout << "?" << endl;
	}

	in.close();
	out.close();

	return 0;
}