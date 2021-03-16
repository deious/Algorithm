#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1, 0 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };

char board[8][8];

void wallMove()
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i == 7 && board[i][j] == '#')
			{
				board[i][j] = '.';
			}
			else if (board[i][j] == '#')
			{
				board[i][j] = '.';
				board[i + 1][j] = '#';
			}
		}
	}
}

bool InRange(int x, int y)
{
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 8; i++)
		cin >> board[i];

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(7, 0, 0));

	bool exitCheck = false;
	int countCheck = 0;

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int count = get<2>(q.front());
		q.pop();

		if (countCheck + 1 == count)
		{
			countCheck++;
			wallMove();
		}

		if (board[x][y] == '#')
			continue;

		if (x == 0 || count >= 8) 
		{
			cout << "1" << "\n";
			return 0;
		}

		for (int i = 0; i < 9; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && board[nx][ny] != '#')
				q.push(make_tuple(nx, ny, count + 1));
		}
	}

	if (!exitCheck)
		cout << "0" << "\n";

	return 0;
}