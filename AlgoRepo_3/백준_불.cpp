#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[1000][1000];
bool check[1000][1000];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int t, w, h;
int moveCount = 0;

queue<pair<int, int>> moves, fire;

bool InRange(int x, int y)
{
	return x >= 0 && x < h && y >= 0 && y < w;
}

bool BFS()
{
	moveCount = 0;
	while (!moves.empty())
	{
		moveCount++;
		int mLen = moves.size();
		int fLen = fire.size();

		while (fLen--)
		{
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] == '.')
				{
					check[nx][ny] = true;
					fire.push(make_pair(nx, ny));
				}
			}
		}

		while (mLen--)
		{
			int x = moves.front().first;
			int y = moves.front().second;
			moves.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (!InRange(nx, ny))
					return true;

				if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] == '.')
				{
					check[nx][ny] = true;
					moves.push(make_pair(nx, ny));
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
	bool result = false;
	cin >> t;

	while (t--)
	{
		while (!moves.empty())
			moves.pop();

		while (!fire.empty())
			fire.pop();

		cin >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '@')
				{
					moves.push(make_pair(i, j));
					check[i][j] = true;
				}

				if (board[i][j] == '*')
				{
					fire.push(make_pair(i, j));
					check[i][j] = true;
				}
			}
		}

		result = BFS();

		if (result)
			cout << moveCount << "\n";
		else
			cout << "IMPOSSIBLE" << "\n";
		
		memset(board, '.', sizeof(board));
		memset(check, false, sizeof(check));
	}

	return 0;
}