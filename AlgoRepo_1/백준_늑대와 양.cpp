#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

char board[500][500];
bool check[500][500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	queue<pair<int, int>> q, q1;

	int R, C;
	cin >> R >> C;

	bool catchSheep = false;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 'S')
				q.push(make_pair(i, j));
			else if (board[i][j] == 'W')
			{
				q1.push(make_pair(i, j));
				check[i][j] = true;
			}
		}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C && board[nx][ny] != 'S' && board[nx][ny] != 'W' && board[nx][ny] != 'D')
				board[nx][ny] = 'D';
		}
	}

	while (!q1.empty())
	{
		int x = q1.front().first;
		int y = q1.front().second;
		q1.pop();

		if (board[x][y] == 'S')
		{
			catchSheep = true;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < R && ny >= 0 && ny < C && !check[nx][ny] && board[nx][ny] != 'D')
			{
				check[nx][ny] = true;
				q1.push(make_pair(nx, ny));
			}
		}
	}

	if (catchSheep)
	{
		cout << "0" << "\n";
	}
	else
	{
		cout << "1" << "\n";

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << board[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}