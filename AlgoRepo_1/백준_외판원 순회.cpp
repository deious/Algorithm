#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int graph[20][20];
int dp[20][1 << 16];
int N;

int solve(int cur, int visited)
{
	if (visited == (1 << N) - 1)
	{ 
		if (graph[cur][0] != 0)
			return graph[cur][0];
		else
			return 2100000000;
	}

	if (dp[cur][visited] != -1)
		return dp[cur][visited];

	dp[cur][visited] = 2100000000;

	for (int i = 1; i < N; i++)
	{
		if (visited & (1 << i) || graph[cur][i] == 0)
			continue;

		dp[cur][visited] = min(dp[cur][visited], solve(i, visited | (1 << i)) + graph[cur][i]);
	}

	return dp[cur][visited];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 1);

	return 0;
}