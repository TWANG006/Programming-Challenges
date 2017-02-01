#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
using namespace std;

int main()
{
	int h, u, d, f;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (scanf("%d %d %d %d", &h, &u, &d, &f), h) {
		int days = 1;
		double fatigue = double(u)*double(f) / 100.0;
		double cur_h = 0;

		while (true) {
			double climb = u - (days - 1)*fatigue;
			if (climb >= 0) {
				cur_h += u - (days - 1)*fatigue;
				if (cur_h > h) {
					printf("success on day %d\n", days);
					break;
				}
			}
			cur_h -= d;
			if (cur_h < 0) {
				printf("failure on day %d\n", days);
				break;
			}
			days++;
		}
	}

	return 0;
}