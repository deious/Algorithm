#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

char board[100][100];
bool check[100][100];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int N;

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !check[nx][ny] && board[x][y] == board[nx][ny])
			{
				q.push(make_pair(nx, ny));
				check[nx][ny] = true;
			}
		}
	}

	return;
}

void bfs_1(int i, int j)
{
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	check[i][j] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		check[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (board[x][y] == 'R' || board[x][y] == 'G')
			{
				if (nx >= 0 && nx < N && ny >= 0 && ny < N && !check[nx][ny] && (board[nx][ny] == 'R' || board[nx][ny] == 'G'))
				{
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
				}
			}
			else if (nx >= 0 && nx < N && ny >= 0 && ny < N && !check[nx][ny] && board[x][y] == board[nx][ny])
			{
				q.push(make_pair(nx, ny));
				check[nx][ny] = true;
			}
		}
	}

	return;
}

int main()
{
	int count = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf(" %1c", &board[i][j]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (!check[i][j])
			{
				bfs(i, j);
				count++;
			}
	}
	
	printf("%d ", count);
	count = 0;
	memset(check, false, sizeof(check));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (!check[i][j])
			{
				bfs_1(i, j);
				count++;
			}
	}

	printf("%d\n", count);

	return 0;
}