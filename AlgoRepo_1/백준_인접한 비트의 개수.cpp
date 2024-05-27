#include <iostream>

using namespace std;

int dp[101][101][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, n, k;
	cin >> T;

	dp[1][0][0] = 1;
	dp[1][0][1] = 1;

	for (int i = 2; i <= 100; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
		}
	}

	while (T--)
	{
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << "\n";
	}

	return 0;
}