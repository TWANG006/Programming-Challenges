#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
using namespace std;

int main()
{
	int n;

	freopen("input.txt", "r", stdin);
	freopen("output_mine.txt", "w", stdout);

	scanf("%d", &n);
	printf("Lumberjacks:\n");

	while (n--) {
		bool asd = false;
		bool dsd = false;
		int pre_len;

		scanf("%d", &pre_len);

		for (int i = 1; i < 10; i++) {
			int cur_len;
			scanf("%d", &cur_len);

			if (cur_len > pre_len)
				asd = true;
			else
				dsd = true;

			pre_len = cur_len;
		}

		(asd&&dsd) ? printf("Unordered\n") : printf("Ordered\n");
	}

	return 0;
}