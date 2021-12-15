#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

char board[1000][1000];
bool check[1000][1000];

int H, W, N;

bool InRange(int x, int y)
{
	return x >= 0 && x < H && y >= 0 && y < W;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> N;

	queue<tuple<int, int, int>> q;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'S')
			{
				check[i][j] = true;
				q.push({ i, j, 0 });
			}
		}
	}

	int num = 1;
	int ans = 0;

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int move = get<2>(q.front());
		q.pop();

		if (board[x][y] - '0' == num)
		{
			ans += move;

			if (num == N)
			{
				cout << ans << "\n";
				return 0;
			}
			else
			{
				memset(check, false, sizeof(check));
				check[x][y] = true;
				q = queue<tuple<int, int, int>>();
				q.push({ x, y, 0 });
			}

			num++;
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && board[nx][ny] != 'X' && !check[nx][ny])
			{
				check[nx][ny] = true;
				q.push({ nx, ny, move + 1 });
			}
		}
	}

	return 0;
}