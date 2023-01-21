#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int board[500][500];
int moveCnt[500][500];

int N;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

int DFS(int x, int y)
{
	if (moveCnt[x][y] != 0)
		return moveCnt[x][y];

	moveCnt[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && board[x][y] < board[nx][ny])
		{
			moveCnt[x][y] = max(moveCnt[x][y], DFS(nx, ny) + 1);
		}
	}

	return moveCnt[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer = max(DFS(i, j), answer);
		}
	}

	cout << answer << "\n";

	return 0;
}