#include <iostream>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

char board[600][600];
bool check[600][600];

int N, M, ans = 0;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int DFS(int x, int y)
{
	check[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] != 'X')
		{
			DFS(nx, ny);
		}
	}

	if (board[x][y] == 'P')
	{
		ans++;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int sx, sy;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'I')
			{
				sx = i;
				sy = j;
			}
		}
	}

	if (!DFS(sx, sy))
	{
		cout << "TT\n";
	}
	else
	{
		cout << DFS(sx, sy) << "\n";
	}

	return 0;
}