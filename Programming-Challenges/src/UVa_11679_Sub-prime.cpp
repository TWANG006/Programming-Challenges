#define _CRT_SECURE_NO_DEPRECATE

#include<cstdio>

int main()
{
	int b; // banks
	int n; // debentures
	int r[25];	// monetary reserves

	while (scanf("%d %d", &b, &n), b || n) {
		for (int i = 0; i < b; i++) {
			scanf("%d", &r[i]);
		}
		
		bool pass = true;

		int d, c, v;	// debtor, creditor, debenture
		while (n--){
			scanf("%d %d %d", &d, &c, &v);
			r[d - 1] -= v;
			r[c - 1] += v;
		}
		for (int i = 0; i < b; i++){
			if (r[i] < 0) {
				pass = false;
				break;
			}
		}

		pass ? printf("S\n") : printf("N\n");
	}

	return 0;
}