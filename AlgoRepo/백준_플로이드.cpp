#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dp[101][101];

void Floyd()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!dp[j][i])
				continue;

			for (int k = 1; k <= n; k++)
			{
				if (!dp[i][k] || j == k)
					continue;

				if (!dp[j][k] || dp[j][i] + dp[i][k] < dp[j][k])
					dp[j][k] = dp[j][i] + dp[i][k];
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (!dp[a][b])
			dp[a][b] = c;
		else
		{
			if (dp[a][b] > c)
				dp[a][b] = c;
		}
	}

	Floyd();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}