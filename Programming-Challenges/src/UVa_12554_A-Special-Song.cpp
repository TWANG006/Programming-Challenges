#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<vector>
#include<string>
using namespace std;


int main()
{
	char names[105][105];
	vector<string> song = { "Happy", "birthday", "to", "you",
					"Happy", "birthday", "to", "you",
					"Happy", "birthday", "to", "Rujia",
					"Happy", "birthday", "to", "you" };

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n = 0;
	scanf("%d", &n);

	// Get names
	for (int i = 0; i < n; i++) {
		scanf("%s", &names[i]);
	}

	int i = 0, j = 0;

	while (i < n || j % 16 != 0) {
		int iN = i%n, jS = j % 16;
		printf("%s: %s\n", names[iN], song[jS].c_str());
		i++, j++;
	}

	return 0;
}