#include <iostream>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

bool check[5][5];
char board[5][5];

int R, C, K, ans = 0;

bool InRange(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

void DFS(int x, int y, int cnt)
{
	if (x == 0 && y == C - 1 && cnt == K)
	{
		ans++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] != 'T')
		{
			check[nx][ny] = true;
			DFS(nx, ny, cnt + 1);
			check[nx][ny] = false;
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C >> K;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}

	check[R - 1][0] = true;
	DFS(R - 1, 0, 1);

	cout << ans << "\n";

	return 0;
}