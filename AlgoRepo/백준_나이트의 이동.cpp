#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int board[301][301] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	queue<pair<int, int>> q;

	int t, size, sx, sy, ex, ey;
	cin >> t;

	while (t--)
	{
		if (!q.empty())
		{
			while (!q.empty())
				q.pop();
		}
		cin >> size >> sx >> sy >> ex >> ey;
		memset(board, 0, sizeof(board));
		q.push(make_pair(sx, sy));

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			if (x == ex && y == ey)
			{
				cout << board[x][y] << "\n";
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (board[nx][ny] == 0 && nx >= 0 && nx < size && ny >= 0 && ny < size)
				{
					board[nx][ny] = board[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	return 0;
}