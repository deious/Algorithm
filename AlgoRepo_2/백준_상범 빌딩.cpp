#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, -1, 1 };

int L, R, C;

char board[30][30][30];
bool check[30][30][30];
bool flag = false;

bool InRange(int x, int y, int z)
{
	return x >= 0 && x < R && y >= 0 && y < C && z >= 0 && z < L;
}

void BFS(int a, int b, int c)
{
	queue<tuple<int, int, int, int>> q;
	q.push({ a, b, c, 0 });
	check[a][b][c] = true;

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		int move = get<3>(q.front());
		q.pop();

		if (board[x][y][z] == 'E')
		{
			cout << "Escaped in " << move << " minute(s).\n";
			flag = true;
			return;
		}

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (InRange(nx, ny, nz) && !check[nx][ny][nz] && board[nx][ny][nz] != '#')
			{
				check[nx][ny][nz] = true;
				q.push({ nx, ny, nz, move + 1 });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (1)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			return 0;

		int startX, startY, startZ;

		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					cin >> board[j][k][i];
					if (board[j][k][i] == 'S')
						startX = j, startY = k, startZ = i;
				}
			}
		}

		flag = false;
		memset(check, false, sizeof(check));
		BFS(startX, startY, startZ);

		if (!flag)
			cout << "Trapped!\n";
	}
}