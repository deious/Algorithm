#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][3];
int cost[1001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	cout << min({ dp[N][0], dp[N][1], dp[N][2] }) << "\n";

	return 0;
}