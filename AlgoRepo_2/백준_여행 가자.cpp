#include <iostream>

using namespace std;

int root[201];

int FindRoot(int x)
{
	if (root[x] == x)
		return x;

	return root[x] = FindRoot(root[x]);
}

void Union(int x, int y)
{
	x = FindRoot(x);
	y = FindRoot(y);

	if (x == y)
		return;

	root[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		root[i] = i;

	int check, x, y;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> check;

			if (check)
			{
				x = FindRoot(i);
				y = FindRoot(j);

				if (x == y)
					continue;

				Union(x, y);
			}
		}
	}

	int root, root1;
	for (int i = 0; i < M; i++)
	{
		if (!i)
		{
			cin >> root;
			root = FindRoot(root);
		}
		else
		{
			cin >> root1;
			root1 = FindRoot(root1);
			if (root == root1)
				continue;
			else
			{
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";
	return 0;
}