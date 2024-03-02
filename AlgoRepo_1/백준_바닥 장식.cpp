#include <iostream>

using namespace std;

int N, M;
char board[50][50];
bool check[50][50];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, - 1, 0, 0 };

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

void DFS(int x, int y, char c)
{
	check[x][y] = true;

	if (c == '-')
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] == c)
			{
				DFS(nx, ny, c);
			}
		}
	}
	else
	{
		for (int i = 2; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] == c)
			{
				DFS(nx, ny, c);
			}
		}
	}
}

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

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!check[i][j])
			{
				DFS(i, j, board[i][j]);
				ans++;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}