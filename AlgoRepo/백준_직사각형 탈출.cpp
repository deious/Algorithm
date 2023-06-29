#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, H, W, Sr, Sc, Fx, Fc;
int board[1000][1000];
bool check[1000][1000];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool InRange(int x, int y)
{
	return x >= 0 && x <= N - H && y >= 0 && y <= M - W;
}

bool MoveCheck(int x, int y, int dir)
{
	bool checkBoard = true;

	if (dir == 0)
	{
		y +=  W;
		for (int i = x; i < x + H ; i++)
		{
			if (board[i][y] == 1)
			{
				checkBoard = false;
				return checkBoard;
			}
		}
	}
	else if (dir == 1)
	{
		x += H;
		for (int i = y; i < y + W; i++)
		{
			if (board[x][i] == 1)
			{
				checkBoard = false;
				return checkBoard;
			}
		}
	}
	else if (dir == 2)
	{
		y--;
		for (int i = x; i < x + H; i++)
		{
			if (board[i][y] == 1)
			{
				checkBoard = false;
				return checkBoard;
			}
		}
	}
	else
	{
		x--;
		for (int i = y; i < y + W; i++)
		{
			if (board[x][i] == 1)
			{
				checkBoard = false;
				return checkBoard;
			}
		}
	}

	return checkBoard;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	queue<tuple<int, int, int>> q;
	cin >> H >> W >> Sr >> Sc >> Fx >> Fc;
	q.push(make_tuple(Sr - 1, Sc - 1, 0));
	check[Sr - 1][Sc - 1] = true;

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int moveCount = get<2>(q.front());
		q.pop();

		if (x == Fx - 1 && y == Fc - 1)
		{
			cout << moveCount << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!check[nx][ny] && InRange(nx, ny) && MoveCheck(x, y, i))
			{
				check[nx][ny] = true;
				q.push(make_tuple(nx, ny, moveCount + 1));
			}
		}
	}

	cout << -1 << "\n";

	return 0;
}