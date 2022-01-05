#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

char board[1500][1500];
bool check[1500][1500];

int R, C;

vector<pair<int, int>> v;
queue<pair<int, int>> wq, wnq, sq, snq;

bool InRange(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

void Thaw()
{
	while (!wq.empty())
	{
		int tx = wq.front().first;
		int ty = wq.front().second;
		wq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (InRange(nx, ny))
			{
				if (board[nx][ny] == 'X')
				{
					board[nx][ny] = '.';
					wnq.push({ nx, ny });
				}
			}
		}
	}
}

bool MoveSwan()
{
	while (!sq.empty())
	{
		int x = sq.front().first;
		int y = sq.front().second;
		sq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !check[nx][ny])
			{
				if (board[nx][ny] == '.')
				{
					check[nx][ny] = true;
					sq.push({ nx, ny });
				}
				else if (board[nx][ny] == 'L')
					return true;
				else if (board[nx][ny] == 'X')
				{
					check[nx][ny] = true;
					snq.push({ nx, ny });
				}
			}
		}
	}

	return false;
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
			if (board[i][j] == 'L')
				v.push_back({ i, j });
			if (board[i][j] != 'X')
				wq.push({ i, j });
		}
	}

	int answer = 0;
	bool flag = false;
	sq.push({ v[0].first, v[0].second });
	check[v[0].first][v[0].second] = true;

	while (true)
	{
		flag = MoveSwan();
		if (!flag)
		{
			Thaw();
			wq = wnq;
			sq = snq;

			while (!wnq.empty()) 
				wnq.pop();
			while (!snq.empty())
				snq.pop();
			answer++;
		}
		else
		{
			cout << answer << "\n";
			return 0;
		}
	}

	return 0;
}