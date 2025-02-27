#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, ans = 0;
int board[50][50];
bool check[50][50];

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int BFS(int x, int y)
{
	queue<tuple<int, int, int>> q;
	q.push({ x, y, 0 });
	check[x][y] = true;

	while (!q.empty())
	{
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int moveCnt = get<2>(q.front());
		q.pop();

		if (board[a][b] == 1)
		{
			return moveCnt;
		}

		for (int i = 0; i < 8; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (InRange(nx, ny) && !check[nx][ny])
			{
				check[nx][ny] = true;
				q.push({ nx, ny, moveCnt + 1 });
			}
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
			{
				memset(check, false, sizeof(check));
				ans = max(BFS(i, j), ans);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}