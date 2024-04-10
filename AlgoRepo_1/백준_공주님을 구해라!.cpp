#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int board[100][100];
bool check[100][100][2];
int N, M, T, ans;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

bool BFS()
{
	queue<tuple<int, int, int, bool>> q;
	q.push({ 0, 0, 0, false });
	check[0][0][0] = true;

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int move = get<2>(q.front());
		bool swordCheck = get<3>(q.front());
		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			ans = move;
			return true;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny))
			{
				if (swordCheck && !check[nx][ny][1])
				{
					check[nx][ny][1] = true;
					q.push({ nx, ny, move + 1, swordCheck });
				}
				else
				{
					if (board[nx][ny] == 2 && !check[nx][ny][1])
					{
						check[nx][ny][1] = true;
						q.push({ nx, ny, move + 1, true });
					}
					else if (!board[nx][ny] && !check[nx][ny][0])
					{
						check[nx][ny][0] = true;
						q.push({ nx, ny, move + 1, swordCheck });
					}
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

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	if (BFS() && ans <= T)
	{
		cout << ans << "\n";
	}
	else
	{
		cout << "Fail\n";
	}

	return 0;
}