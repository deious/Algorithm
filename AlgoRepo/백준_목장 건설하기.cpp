#include <iostream>
#include <algorithm>

using namespace std;

int board[1001][1001];
int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	int answer = 0;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (board[i][j])
				continue;

			dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
			answer = max(answer, dp[i][j]);
		}
	}

	cout << answer << "\n";

	return 0;
}