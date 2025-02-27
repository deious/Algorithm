#include <iostream>
#include <vector>

using namespace std;

vector<int> v[100001];
int dp[100001];

void DFS(int num)
{
	for (int next : v[num])
	{
		dp[next] += dp[num];
		DFS(next);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;

		if (a != -1)
		{
			v[a].push_back(i);
		}
	}

	int num, w;
	for (int i = 0; i < m; i++)
	{
		cin >> num >> w;
		dp[num] += w;
	}

	DFS(1);

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}

	return 0;
}