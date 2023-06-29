#include <iostream>
#include <queue>

using namespace std;

int dx[] = { -2, -2, 0, 0, 2, 2 };
int dy[] = { -1, 1, -2, 2, -1, 1 };

int board[201][201] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int size, r1, c1, r2, c2;
	cin >> size >> r1 >> c1 >> r2 >> c2;

	queue<pair<int, int>> q;

	q.push(make_pair(r1, c1));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == r2 && y == c2) break;

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (board[nx][ny] == 0 && nx >=0 && nx < size && ny >= 0 && ny < size)
			{
				board[nx][ny] = board[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	if (board[r2][c2] == 0)
		board[r2][c2] = -1;

	cout << board[r2][c2] << "\n";

	return 0;
}