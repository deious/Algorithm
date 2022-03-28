#include <iostream>

using namespace std;

int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (j == 0 || i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}