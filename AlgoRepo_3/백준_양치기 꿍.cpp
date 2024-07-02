#include <iostream>
#include <queue>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

char board[250][250];
bool check[250][250];

int R, C, sheep = 0, wolf = 0;

bool InRange(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	check[x][y] = true;

	int tempWolf = 0, tempSheep = 0;

	if (board[x][y] == 'v')
	{
		tempWolf++;
	}
	else if (board[x][y] == 'k')
	{
		tempSheep++;
	}

	while (!q.empty())
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (InRange(nx, ny) && board[nx][ny] != '#' && !check[nx][ny])
			{
				if (board[nx][ny] == 'v')
				{
					tempWolf++;
				}
				else if (board[nx][ny] == 'k')
				{
					tempSheep++;
				}

				check[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	if (tempWolf >= tempSheep)
	{
		wolf += tempWolf;
	}
	else
	{
		sheep += tempSheep;
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (!check[i][j] && board[i][j] != '#')
			{
				BFS(i, j);
			}
		}
	}

	cout << sheep << " " << wolf << "\n";

	return 0;
}