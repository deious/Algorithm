#include <iostream>
#include <cstring>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int N, M;
int board[300][300];
int tempBoard[300][300];
bool check[300][300];

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny])
		{
			check[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

bool meltIceMoutain()
{
	int x = 0, y = 0;
	int waterCount = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!board[i][j])
				continue;
			else
				waterCount = 0;

			for (int k = 0; k < 4; k++)
			{
				x = i + dx[k];
				y = j + dy[k];

				if (InRange(x, y) && !board[x][y])
					waterCount++;
			}

			if (board[i][j] - waterCount >= 0)
			{
				tempBoard[i][j] = board[i][j] - waterCount;
			}
			else
				tempBoard[i][j] = 0;

		}
	}

	if (!waterCount)
		return false;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			board[i][j] = tempBoard[i][j];

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int time = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	while (true)
	{
		int island = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!check[i][j] && board[i][j])
				{
					island++;
					if (island == 2)
					{
						cout << time << "\n";
						return 0;
					}

					check[i][j] = true;
					dfs(i, j);

				}
			}
		}

		if (!meltIceMoutain()) 
		{
			cout << "0\n";
			return 0;
		}

		memset(check, false, sizeof(check));
		time++;
	}

	return 0;
}