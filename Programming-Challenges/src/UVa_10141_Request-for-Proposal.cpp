#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<map>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n, p;
	int t = 1;
	string seperator = "";

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (scanf("%d %d", &n, &p), n || p) {
		
		string names;
		string best_name;
		double best_price = -1.0;
		int best_compliance = -1;

		cout << seperator;
		seperator = "\n";

		cin.ignore();
		while (n--) {
			getline(cin, names);
		}

		while (p--)
		{
			string temp_p;
			getline(cin, temp_p);

			double temp_price;
			int temp_compliance;
			scanf("%lf %d", &temp_price, &temp_compliance);

			cin.ignore();
			for (int i = 0; i < temp_compliance; i++)
				getline(cin, names);

			if (temp_compliance > best_compliance ||
				temp_compliance == best_compliance && temp_price < best_price) {
				best_name = temp_p;
				best_price = temp_price;
				best_compliance = temp_compliance;
			}
		}
		
		printf("RFP #%d\n", t++);
		printf("%s\n", best_name.c_str());
	}

	return 0;
}