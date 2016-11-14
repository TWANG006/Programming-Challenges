#include "disjoint-set.h"

using namespace std;

int main()
{
	vector<int> parent;
	vector<int> size;

	int n = 0, m = 0;

	cin >> n;

	MakeSet(parent, size, n);

	Union_set(parent, size, 2 - 1, 3 - 1);

	for (int i = 0; i < n; i++)
	{
		cout << size[i] << ", ";
	}
	cout << endl;

	Union_set(parent, size, 7 - 1, 6 - 1);

	for (int i = 0; i < n; i++)
	{
		cout << size[i] << ", ";
	}
	cout << endl;

	Union_set(parent, size, 6 - 1, 3 - 1);

	for (int i = 0; i < n; i++)
	{
		cout << size[i] << ", ";
	}
	cout << endl;

	Union_set(parent, size, 5 - 1, 9 - 1);

	for (int i = 0; i < n; i++)
	{
		cout << size[i] << ", ";
	}
	cout << endl;

	Union_set(parent, size, 10 - 1, 4 - 1);

	for (int i = 0; i < n; i++)
	{
		cout << size[i] << ", ";
	}
	cout << endl;

	Union_set(parent, size, 4 - 1, 5 - 1);

	for (int i = 0; i < n; i++)
	{
		cout << size[i] << ", ";
	}
	cout << endl;


	return 0;
}