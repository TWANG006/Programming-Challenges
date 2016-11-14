#include "disjoint-set.h"

int root(std::vector<int>& root, int i)
{
	while (root[i] != i) {
		root[i] = root[root[i]];
		i = root[i];
	}

	return i;
}

void MakeSet(std::vector<int>& parent, std::vector<int>& size, int N)
{
	for (int i = 0; i < N; i++)
	{
		parent.push_back(i);
		size.push_back(1);
	}
}

bool find_set(std::vector<int>& parent, int a, int b)
{
	if (root(parent, a) == root(parent, b))
		return true;
	else
		return false;
}

void Union_set(std::vector<int>& parent, std::vector<int>& size, int a, int b)
{
	int root_a = root(parent, a);
	int root_b = root(parent, b);

	if (size[root_a] < size[root_b])
	{
		parent[root_a] = parent[root_b];
		size[root_b] += size[root_a];
		size[root_a] = 0;
	}
	else
	{
		parent[root_b] = parent[root_a];
		size[root_a] += size[root_b];
		size[root_b] = 0;
	}
}
