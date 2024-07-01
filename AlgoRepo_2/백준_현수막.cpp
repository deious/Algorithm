#include <iostream>

using namespace std;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int board[250][250];
bool check[250][250];

int M, N;

bool InRange(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}

void DFS(int x, int y)
{
	check[x][y] = true;

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny])
		{
			DFS(nx, ny);
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!check[i][j] && board[i][j])
			{
				DFS(i, j);
				answer++;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}