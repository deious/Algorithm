#include <iostream>

using namespace std;

int dx[] = { 0, 1, 1 };
int dy[] = { 1, 1, 0 };

int board[17][17];
int N, ans = 0;

bool InRange(int x, int y, int status)
{
	if (x > 0 && x <= N && y > 0 && y <= N)
	{
		if (!status)
		{
			if (!board[x][y + 1])
				return true;
		}
		else if (status == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				if (!board[x + dx[i]][y + dy[i]])
					continue;
				else
					return false;
			}

			return true;
		}
		else
		{
			if (!board[x + 1][y])
				return true;
		}
	}

	return false;
}

void DFS(int x, int y, int status)
{
	if (x == N && y == N)
	{
		ans++;
		return;
	}

	int nx, ny;
	if (!status)
	{
		for (int i = 0; i < 2; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (InRange(x, y, i))
				DFS(nx, ny, i);
		}
	}
	else if (status == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (InRange(x, y, i))
				DFS(nx, ny, i);
		}
	}
	else
	{
		for (int i = 1; i < 3; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (InRange(x, y, i))
				DFS(nx, ny, i);
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	DFS(1, 2, 0);

	cout << ans << "\n";

	return 0;
}