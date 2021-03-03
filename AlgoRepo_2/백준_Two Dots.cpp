#include<cstdio>

using namespace std;

char board[50][50];
bool check[50][50];
int dist[50][50];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int N, M;

bool dfs(int x, int y, int cnt)
{
	if (check[x][y])
	{
		if (cnt - dist[x][y] >= 4)
			return true;
		else
			return false;
	}

	check[x][y] = true;
	dist[x][y] = cnt;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M)
		{
			if (board[nx][ny] == board[x][y])
			{
				if (dfs(nx, ny, cnt + 1))
					return true;
			}
		}
	}
	return false;
}

int main()
{
	bool ynCheck = false;

	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf(" %1c", &board[i][j]);
	}

	for (int i = 0; i < N; i++)
	{
		if (ynCheck)
			break;
		for (int j = 0; j < M; j++)
		{
			if (!check[i][j])
			{
				if (dfs(i, j, 0))
				{
					printf("Yes\n");
					ynCheck = true;
					break;
				}
			}
		}
	}
	
	if (!ynCheck)
		printf("No\n");

	return 0;
}