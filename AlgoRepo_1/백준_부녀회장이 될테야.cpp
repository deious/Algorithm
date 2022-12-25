#include <iostream>

using namespace std;

int dp[15][15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t, k, n;
	cin >> t;

	for (int i = 0; i < 15; i++)
	{
		dp[0][i] = i;
	}

	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	while (t--)
	{
		cin >> k >> n;
		cout << dp[k][n] << "\n";
	}

	return 0;
}