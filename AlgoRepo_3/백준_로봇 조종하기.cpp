#include <iostream>

using namespace std;

int dp[1000][1000];
int board[1000][1000];
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	dp[0][0] = board[0][0];

	for (int j = 1; j < M; j++)
	{
		dp[0][j] = dp[0][j - 1] + board[0][j];
	}
	
	for (int i = 1; i < N; i++)
	{
		int left[1000], right[1000];
		left[0] = dp[i - 1][0] + board[i][0];

		for (int j = 1; j < M; j++) 
		{
			left[j] = max(dp[i - 1][j], left[j - 1]) + board[i][j];
		}

		right[M - 1] = dp[i - 1][M - 1] + board[i][M - 1];

		for (int j = M - 2; j >= 0; j--) 
		{
			right[j] = max(dp[i - 1][j], right[j + 1]) + board[i][j];
		}

		for (int j = 0; j < M; j++) 
		{
			dp[i][j] = max(left[j], right[j]);
		}
	}

	cout << dp[N - 1][M - 1] << "\n";

	return 0;
}