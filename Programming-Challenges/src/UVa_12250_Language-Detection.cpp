/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=244&page=show_problem&problem=3402
*/

#include<string>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	string s;
	int caseNum = 1;

	ifstream in("input.txt", ios::in);
	ofstream out("output_mine.txt", ios::out | ios::trunc);
	
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());

	while (cin >> s, s != "#")
	{
		if (s == "HELLO") cout << "Case " << caseNum++ << ": " << "ENGLISH" << endl;
		else if (s == "HOLA") cout << "Case " << caseNum++ << ": " << "SPANISH" << endl;
		else if (s == "HALLO") cout << "Case " << caseNum++ << ": " << "GERMAN" << endl;
		else if (s == "BONJOUR") cout << "Case " << caseNum++ << ": " << "FRENCH" << endl;
		else if (s == "CIAO") cout << "Case " << caseNum++ << ": " << "ITALIAN" << endl;
		else if (s == "ZDRAVSTVUJTE") cout << "Case " << caseNum++ << ": " << "RUSSIAN" << endl;
		else cout << "Case " << caseNum++ << ": " << "UNKNOWN" << endl;
	}

	in.close();
	out.close();

	return 0;
}