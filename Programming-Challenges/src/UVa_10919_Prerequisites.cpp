#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	int k, m;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (scanf("%d", &k), k)
	{
		scanf("%d", &m);

		bool meet = true;

		vector<string> courses(k);
		for (int i = 0; i < k; i++)
		{
			cin >> courses[i];
		}

		// Get num of categories and requirement of c
		int c, r;
		while (m--)
		{
			scanf("%d %d", &c, &r);
			vector<string> code(c);
			for (int i = 0; i < c; i++)
			{
				cin >> code[i];
			}

			int count = 0;
			for (int i = 0; i < k; i++)
			{
				if (find(code.begin(), code.end(), courses[i]) != code.end())
					count++;
			}

			if (count < r) {
				meet = false;
			}
		}

		meet ? printf("yes\n") : printf("no\n");
	}
	return 0;
}