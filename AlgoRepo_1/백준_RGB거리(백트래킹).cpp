#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cost[1001][3];
int dp[1001][3];
int N;

int Calculate(int n, int color)
{
	if (n > N)
	{
		return 0;
	}

	if (dp[n][color] != -1)
	{
		return dp[n][color];
	}

	int ret = cost[n][color];

	if (color == 0)
	{
		ret += min(Calculate(n + 1, 1), Calculate(n + 1, 2));
	}
	else if (color == 1)
	{
		ret += min(Calculate(n + 1, 0), Calculate(n + 1, 2));
	}
	else
	{
		ret += min(Calculate(n + 1, 0), Calculate(n + 1, 1));
	}

	dp[n][color] = ret;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	memset(dp, -1, sizeof(dp));

	int ans = min({ Calculate(0, 0), Calculate(0, 1), Calculate(0, 2) });

	cout << ans << "\n";

	return 0;
}