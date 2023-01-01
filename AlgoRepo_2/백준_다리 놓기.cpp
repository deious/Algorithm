#include <iostream>

using namespace std;

int dp[31][31];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N, M;

	for (int i = 1; i < 31; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 2; i < 31; i++)
	{
		for (int j = 2; j < 31; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		}
	}

	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		cout << dp[N][M] << "\n";
	}

	return 0;
}