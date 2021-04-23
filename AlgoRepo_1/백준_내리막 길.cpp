#include <iostream>

using namespace std;

int dp[500][500];
int board[500][500];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int N, M;

bool InRange(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}

int dfs(int x, int y)
{
	if (x == M - 1 && y == N - 1)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && board[x][y] > board[nx][ny])
			dp[x][y] += dfs(nx, ny);
	}

	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0) << "\n";

	return 0;
}