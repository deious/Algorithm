#include <iostream>
#include <cstring>

using namespace std;

int dx[] = { 0, 1, 0 ,-1 };
int dy[] = { 1, 0, -1, 0 };

char board[100][100];
bool check[100][100];
int H, W;

bool InRange(int x, int y)
{
	return x >= 0 && x < H && y >= 0 && y < W;
}

void DFS(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && board[nx][ny] == '#' && !check[nx][ny])
		{
			check[nx][ny] = true;
			DFS(nx, ny);
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> H >> W;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> board[i][j];
			}
		}

		int ans = 0;
		memset(check, false, sizeof(check));
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (!check[i][j] && board[i][j] == '#')
				{
					check[i][j] = true;
					DFS(i, j);
					ans++;
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}