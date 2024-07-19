#include <iostream>
#include <cstring>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

char board[500][500];
int dp[500][500];

int N, M;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int DirCheck(int x, int y)
{
	if (board[x][y] == 'U')
	{
		return 0;
	}
	else if (board[x][y] == 'R')
	{
		return 1;
	}
	else if (board[x][y] == 'D')
	{
		return 2;
	}
	else
	{
		return 3;
	}
}

int DFS(int x, int y)
{
	if (!InRange(x, y))
	{
		return 1;
	}

	if (dp[x][y] != -1)
	{
		return dp[x][y];
	}

	dp[x][y] = 0;
	int dir = DirCheck(x, y);

	dp[x][y] = DFS(x + dx[dir], y + dy[dir]);

	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
	}

	memset(dp, -1, sizeof(dp));

	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer += DFS(i, j);
		}
	}

	cout << answer << "\n";

	return 0;
}