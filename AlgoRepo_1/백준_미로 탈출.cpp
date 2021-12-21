#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int board[1001][1001];
bool check[1001][1001][2];
int N, M;

bool InRange(int x, int y)
{
	return x > 0 && x <= N && y > 0 && y <= M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int Hx, Hy, Ex, Ey;
	cin >> N >> M >> Hx >> Hy >> Ex >> Ey;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> board[i][j];

	queue<tuple<int, int, int, int>> q;
	q.push({ Hx, Hy, 0, 0 });
	check[Hx][Hy][0] = true;

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int useStick = get<2>(q.front());
		int moveCount = get<3>(q.front());
		q.pop();

		if (x == Ex && y == Ey)
		{
			cout << moveCount << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny))
			{
				if (!useStick)
				{
					if (board[nx][ny] == 0 && !check[nx][ny][0])
					{
						q.push({ nx, ny, useStick, moveCount + 1 });
						check[nx][ny][0] = true;
					}
					else if (board[nx][ny] == 1 && !check[nx][ny][1])
					{
						q.push({ nx, ny, useStick + 1, moveCount + 1 });
						check[nx][ny][1] = true;
					}
				}
				else
				{
					if (board[nx][ny] == 0 && !check[nx][ny][1])
					{
						q.push({ nx, ny, useStick, moveCount + 1 });
						check[nx][ny][1] = true;
					}
				}
			}
		}
	}

	cout << "-1\n";
	
	return 0;
}