#include <iostream>

using namespace std;

int root[10001];
int cost[10001];
bool check[10001];

int Find(int num)
{
	if (root[num] == num)
	{
		return num;
	}
	else
	{
		return root[num] = Find(root[num]);
	}
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y)
	{
		if (cost[x] < cost[y])
		{
			root[y] = x;
		}
		else
		{
			root[x] = y;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, k;
	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++)
	{
		root[i] = i;
		cin >> cost[i];
	}

	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		Union(a, b);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int temp = Find(i);
		if (!check[temp])
		{
			check[temp] = true;
			ans += cost[temp];
		}
	}

	if (ans > k)
	{
		cout << "Oh no\n";
	}
	else
	{
		cout << ans << "\n";
	}

	return 0;
}