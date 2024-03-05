#include <iostream>

using namespace std;

int board[301][301];
int dp[301][301];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + board[i][j];
		}
	}

	cin >> K;

	int x1, x2, y1, y2;
	while (K--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}