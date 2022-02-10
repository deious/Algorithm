#include <iostream>

using namespace std;

int parent[1000001];

int Find(int x)
{
	if (parent[x] == x)
		return x;

	return parent[x] = Find(parent[x]);
}

void Merge(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y)
		return;

	parent[y] = x;
}

bool IsUnion(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x == y)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (a == 0)
			Merge(b, c);
		else
		{
			if (IsUnion(b, c))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}