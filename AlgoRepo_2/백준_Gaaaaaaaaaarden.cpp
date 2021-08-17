#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, M, G, R;

int board[50][50];

vector<pair<int, int>> pos;

struct info
{
	int x, y, color, time;
};

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> G >> R;

	int tCount = 0;
	int rCount = R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 2)
			{
				pos.push_back(make_pair(i, j));
				tCount++;
			}
		}
	}

	vector<int> v(tCount, 1);

	for (int i = 0; i < R + G; i++)
	{
		if (rCount > 0)
		{
			v[i] = 3;
			rCount--;
		}
		else
			v[i] = 2;
	}

	int ans = 0;

	do
	{
		int ansCount = 0;
		int tempBoard[50][50];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				tempBoard[i][j] = board[i][j];

		int timeBoard[50][50];
		memset(timeBoard, 0, sizeof(timeBoard));
		queue<info> q;

		int len = v.size();
		for (int i = 0; i < len; i++)
		{
			if (v[i] == 3)
			{
				tempBoard[pos[i].first][pos[i].second] = 4;
				q.push({ pos[i].first, pos[i].second, 4, 0 });
			}
			else if (v[i] == 2)
			{
				tempBoard[pos[i].first][pos[i].second] = 3;
				q.push({ pos[i].first, pos[i].second, 3, 0 });
			}
		}

		while (!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			int color = q.front().color;
			int time = q.front().time;
			q.pop();

			if (tempBoard[x][y] == 5)
				continue;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (InRange(nx, ny) && tempBoard[nx][ny] > 0 && tempBoard[nx][ny] != color && tempBoard[nx][ny] != 5)
				{
					if (tempBoard[nx][ny] == 1 || tempBoard[nx][ny] == 2)
					{
						tempBoard[nx][ny] = color;
						timeBoard[nx][ny] = time + 1;
						q.push({ nx, ny, color, time + 1 });
					}
					else if (tempBoard[nx][ny] != 1 && tempBoard[nx][ny] != 2 && timeBoard[nx][ny] == time + 1)
					{
						tempBoard[nx][ny] = 5;
						timeBoard[nx][ny] = time + 1;
						ansCount++;
					}
				}
			}
		}

		ans = max(ans, ansCount);
	} while (prev_permutation(v.begin(), v.end()));

	cout << ans << "\n";

	return 0;
}