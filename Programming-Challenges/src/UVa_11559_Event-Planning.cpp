#define _CRT_SECURE_NO_DEPRECATE
#define INF 5000005
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n, h, w, a;	// participants, hotels, weeks, price, beds
	long int b, p;	// budget, price per-night
	

	while (scanf("%d %ld %d %d", &n, &b, &h, &w) != EOF)
	{
		long int min_cost = INF;
		while (h--)
		{
			scanf("%ld", &p);	// price per night
			int weeks = w;
			while (weeks--) {
				scanf("%d", &a);
				if (a >= n){
					long np = n*p;
					if (np < b && np < min_cost)
						min_cost = np;
				}
			}
		}

		(min_cost == INF) ? printf("stay home\n") : printf("%ld\n", min_cost);
	}

	return 0;
}