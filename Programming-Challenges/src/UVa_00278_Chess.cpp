#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>
#include<cmath>

int main(void) {

	float a, b;
	char c;
	int n;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d\n", &n);
	while (n) {
		n--;
		scanf("%c %f %f\n", &c, &a, &b);
		if (c == 'k') printf("%.0f\n", ceil(a*b / 2.0));
		else if (c == 'K') printf("%.0f\n", (ceil(a / 2.0)*ceil(b / 2.0)));
		else printf("%.0f\n", (a < b ? a : b));
	}
}