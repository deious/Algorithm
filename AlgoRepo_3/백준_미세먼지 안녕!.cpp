#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dx[] = { 1, -1 ,0 ,0 };
int dy[] = { 0, 0, -1, 1 };

int board[51][51];
int tempBoard[51][51];
int R, C, T;

vector<pair<int, int>> airCleaner;

bool InRange(int x, int y)
{
	return x > 0 && x <= R && y > 0 && y <= C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C >> T;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == -1)
				airCleaner.push_back(make_pair(i, j));
		}
	}

	while (T--)
	{
		queue<tuple<int, int, int>> q;

		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				if (board[i][j] > 0)
					q.push(make_tuple(i, j, board[i][j]));
			}
		}

		while (!q.empty())
		{
			int x = get<0>(q.front());
			int y = get<1>(q.front());
			int dust = get<2>(q.front());
			q.pop();

			int sucessCount = 0;
			int cost = 0;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				cost = dust / 5;

				if (InRange(nx, ny) && board[nx][ny] != -1)
				{
					sucessCount++;
					tempBoard[nx][ny] += cost;
				}
			}

			board[x][y] -= cost * sucessCount;
		}

		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++)
				board[i][j] += tempBoard[i][j];

		memset(tempBoard, 0, sizeof(tempBoard));

		int x = airCleaner[0].first;
		int y = airCleaner[0].second;

		for (int i = x; i > 1; i--)
			board[i][1] = board[i - 1][1];

		for (int i = 1; i < C; i++)
			board[1][i] = board[1][i + 1];

		for (int i = 1; i < x; i++)
			board[i][C] = board[i + 1][C];

		for (int i = C; i > 2; i--)
			board[x][i] = board[x][i - 1];

		board[x][y + 1] = 0;
		board[x][y] = -1;

		x = airCleaner[1].first;
		y = airCleaner[1].second;

		for (int i = x; i < R; i++)
			board[i][1] = board[i + 1][1];

		for (int i = 1; i < C; i++)
			board[R][i] = board[R][i + 1];

		for (int i = R; i > x; i--)
			board[i][C] = board[i - 1][C];

		for (int i = C; i > 2; i--)
			board[x][i] = board[x][i - 1];

		board[x][y + 1] = 0;
		board[x][y] = -1;
	}

	int ans = 0;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			ans += board[i][j];

	cout << ans + 2 << "\n";

	return 0;
}