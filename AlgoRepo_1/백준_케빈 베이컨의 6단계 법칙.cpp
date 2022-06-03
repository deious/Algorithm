#include <iostream>

using namespace std;

int dp[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int a, b;
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = 1000;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		dp[a][b] = 1;
		dp[b][a] = 1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dp[i][k] + dp[k][j] < dp[i][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}

	int temp = 1000;
	int tAnswer = 0;
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		tAnswer = 0;
		for (int j = 1; j <= N; j++)
			tAnswer += dp[i][j];

		if (tAnswer < temp)
		{
			temp = tAnswer;
			answer = i;
		}
	}

	cout << answer << "\n";

	return 0;
}