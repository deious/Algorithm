#include <iostream>

using namespace std;

int dx[] = { -1, 0, 1 };
int dy[] = { 1, 1, 1 };

char board[10000][500];
bool check[10000][500];

int R, C, answer = 0;
bool endCheck = false;

bool InRange(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

void DFS(int x, int y)
{
	check[x][y] = true;

	if (y == C - 1)
	{
		answer++;
		endCheck = true;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && board[nx][ny] == '.' && !check[nx][ny])
		{
			if (endCheck)
				return;
			DFS(nx, ny);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];

	for (int i = 0; i < R; i++)
	{
		endCheck = false;
		DFS(i, 0);
	}

	cout << answer << "\n";

	return 0;
}