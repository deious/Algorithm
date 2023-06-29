#include <iostream>

using namespace std;

bool check[101][101];
bool visit[101];

int c, n, a, b, ans = 0;

void dfs(int num)
{
	visit[num] = true;

	for (int i = 1; i <= c; i++)
	{
		if (check[num][i] && !visit[i])
		{
			ans++;
			dfs(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> c >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		check[a][b] = true;
		check[b][a] = true;
	}

	dfs(1);
	cout << ans << "\n";

	return 0;
}