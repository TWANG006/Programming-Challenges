#define _CRT_SECURE_NO_DEPRECATE

#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int n;	
	string seperator = "";

	ifstream in("input.txt", ios::in);
	cin.rdbuf(in.rdbuf());
	ofstream out("output.txt", ios::out | ios::trunc);
	cout.rdbuf(out.rdbuf());

	while (cin >> n) {
		vector<string> names;
		unordered_map<string, int> myMap;
		cout << seperator;
		seperator = "\n";
		string temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			names.push_back(temp);
			myMap.insert(make_pair(temp, 0));
		}
		string name;
		int money, num_gifts;

		for (int i = 0; i < n; i++) {
			cin >> name >> money >> num_gifts;
			if (num_gifts != 0) {
				int distribute = money / num_gifts;
				myMap[name] += -money + (money - distribute*num_gifts);
				while (num_gifts--) {
					cin >> temp;
					myMap[temp] += distribute;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << names[i] << " " << myMap[names[i]] << endl;
		}
	}

	in.close();
	out.close();

	return 0;
}