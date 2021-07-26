#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int board[101][101];
bool check[101][101];

int n, m;
int deleteCheese = 0;
int tempCheese = 0;

bool InRange(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	int dCheese = 0;

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny])
			{
				board[nx][ny] = 0;
				check[nx][ny] = true;
				dCheese++;
			}
			else if (InRange(nx, ny) && !check[nx][ny] && !board[nx][ny])
			{
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}

	tempCheese += dCheese;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	memset(board, 0, sizeof(board));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int time = 0;

	while (1)
	{
		tempCheese = 0;

		BFS(0, 0);

		memset(check, false, sizeof(check));

		if (!tempCheese)
		{
			cout << time << "\n" << deleteCheese << "\n";
			return 0;
		}
		else
			deleteCheese = tempCheese;

		time++;
	}

	return 0;
}