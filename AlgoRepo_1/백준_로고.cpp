#include <iostream>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int board[2001][2001];

bool InRange(int x, int y)
{
	return x >= 0 && x <= 2000 && y >= 0 && y <= 2000;
}

void DFS(int y, int x)
{
	if (!InRange(x, y) || board[y][x] == 2 || board[y][x] == 0)
		return;

	board[y][x] = 2;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		DFS(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, x1, y1, x2, y2;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = (x1 + 500) * 2;
		y1 = (y1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y2 = (y2 + 500) * 2;

		for (int j = x1; j <= x2; j++)
		{
			board[y1][j] = 1;
			board[y2][j] = 1;
		}

		for (int j = y1; j <= y2; j++)
		{
			board[j][x1] = 1;
			board[j][x2] = 1;
		}
	}

	int answer = 0;
	for (int i = 0; i <= 2000; i++)
	{
		for (int j = 0; j <= 2000; j++)
		{
			if (board[i][j] == 1)
			{
				DFS(i, j);
				answer++;
			}
		}
	}

	if (board[1000][1000] == 2)
		answer--;

	cout << answer << "\n";

	return 0;
}