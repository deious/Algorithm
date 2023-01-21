#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

char board[102][102];
int doors[102][102][3];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int h, w;

bool InRange(int x, int y)
{
	return x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> h >> w;
		memset(doors, -1, sizeof(doors));

		for (int i = 0; i <= h + 1; i++)
			for (int j = 0; j <= w + 1; j++)
				board[i][j] = '.';

		pair<int, int> start[3];
		start[0] = { 0, 0 };

		int index = 1;

		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cin >> board[i][j];

				if (board[i][j] == '$')
				{
					start[index++] = { i, j };
					board[i][j] = '.';
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			deque<pair<int, int>> q;
			q.push_back(start[i]);

			doors[q.front().first][q.front().second][i] = 0;

			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop_front();

				for (int j = 0; j < 4; j++)
				{
					int nx = x + dx[j];
					int ny = y + dy[j];

					if (InRange(nx, ny) && doors[nx][ny][i] == -1 && board[nx][ny] != '*')
					{
						if (board[nx][ny] == '.')
						{
							doors[nx][ny][i] = doors[x][y][i];
							q.push_front(make_pair(nx, ny));
						}
						else if (board[nx][ny] == '#')
						{
							doors[nx][ny][i] = doors[x][y][i] + 1;
							q.push_back(make_pair(nx, ny));
						}
					}
				}
			}
		}

		int answer = 2100000000;
		int temp = 0;

		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				if (board[i][j] == '*')
					continue;

				if (doors[i][j][0] == -1 || doors[i][j][1] == -1 || doors[i][j][2] == -1)
					continue;

				temp = doors[i][j][0] + doors[i][j][1] + doors[i][j][2];

				if (board[i][j] == '#')
					temp -= 2;

				if (answer > temp)
					answer = temp;
			}
		}

		cout << answer << "\n";
	}

	return 0;
}