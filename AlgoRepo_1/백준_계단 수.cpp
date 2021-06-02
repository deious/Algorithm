#include <iostream>

using namespace std;

int dp[101][10][1024];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, ans = 0;
	cin >> N;

	for (int i = 1; i < 10; i++)
		dp[1][i][1 << i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 1024; k++)
			{
				if (!j)
					dp[i][0][k | 1] = (dp[i][0][k | 1] + dp[i - 1][1][k]) % 1000000000;
				else if (j == 9)
					dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % 1000000000;
				else
				{
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % 1000000000;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % 1000000000;
				}
			}
		}
	}

	for (int i = 0; i < 10; i++)
		ans = (ans + dp[N][i][1023]) % 1000000000;

	cout << ans << "\n";

	return 0;
}