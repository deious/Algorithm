#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int dp[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INT_MAX;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			dp[i][j] = 10000000;
		}
	}

	int len = fares.size();
	for (int i = 0; i < len; i++)
	{
		dp[fares[i][0]][fares[i][1]] = fares[i][2];
		dp[fares[i][1]][fares[i][0]] = fares[i][2];
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == k)
				continue;
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		answer = min(answer, dp[s][i] + dp[i][a] + dp[i][b]);

	return answer;
}