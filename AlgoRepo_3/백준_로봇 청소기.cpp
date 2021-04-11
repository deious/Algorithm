#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, r, c, d;
int board[50][50];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
 
bool check[50][50];

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> r >> c >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(r, c, d));

	int ans = 0;

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int dir = get<2>(q.front());
		q.pop();

		if (!board[x][y] && !check[x][y])
			ans++;

		check[x][y] = true;

		int count = 0;
		for (int i = dir; count < 4; i--)
		{
			dir--;
			if (dir < 0)
				dir = 3;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (InRange(nx, ny) && !board[nx][ny] && !check[nx][ny])
			{
				q.push(make_tuple(nx, ny, dir));
				break;
			}

			count++;
		}

		if (count == 4)
		{
			int tDir = dir;
			if (dir > 1)
				tDir -= 2;
			else
			{
				if (dir == 1)
					tDir = 3;
				else
					tDir = 2;
			}

			int nx = x + dx[tDir];
			int ny = y + dy[tDir];

			if (InRange(nx, ny) && !board[nx][ny])
				q.push(make_tuple(nx, ny, dir));
		}
	}

	cout << ans << "\n";

	return 0;
}