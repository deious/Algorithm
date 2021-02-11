#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][3];
int cost[1001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, minNum = 1000001;
	cin >> N;


	for (int i = 1; i <= N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j) 
				dp[1][j] = cost[1][i];
			else 
				dp[1][j] = 1000001;
		}

		for (int j = 2; j <= N; j++)
		{
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + cost[j][2];
		}

		for (int j = 0; j < 3; j++)
		{
			if (i != j)
				minNum = min(minNum, dp[N][j]);
		}
	}

	cout << minNum << "\n";

	return 0;
}