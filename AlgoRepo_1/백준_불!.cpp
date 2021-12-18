#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int R, C;
char board[1000][1000];
int fireBoard[1000][1000];
bool check[1000][1000];

bool InRange(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;
	char c;
	queue<tuple<int, int, int>> fq;
	queue<tuple<int, int, int>> jq;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'F')
			{
				fq.push({ i, j, 0 });
				fireBoard[i][j] = 0;
			}
			else if (board[i][j] == 'J')
			{
				jq.push({ i, j, 0 });
				check[i][j] = true;
				fireBoard[i][j] = 2100000000;
			}
			else
				fireBoard[i][j] = 2100000000;
		}
	}

	while (!fq.empty())
	{
		int x = get<0>(fq.front());
		int y = get<1>(fq.front());
		int time = get<2>(fq.front());
		fq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && (board[nx][ny] == '.' || board[nx][ny] == 'J') && fireBoard[nx][ny] > time + 1)
			{
				fq.push({ nx, ny, time + 1 });
				fireBoard[nx][ny] = time + 1;
			}
		}
	}

	while (!jq.empty())
	{
		int x = get<0>(jq.front());
		int y = get<1>(jq.front());
		int time = get<2>(jq.front());
		jq.pop();

		if (x == 0 || x == R - 1 || y == 0 || y == C - 1)
		{
			cout << time + 1 << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && board[nx][ny] == '.' && fireBoard[nx][ny] > time + 1 && !check[nx][ny])
			{
				check[nx][ny] = true;
				jq.push({ nx, ny, time + 1 });
			}
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}