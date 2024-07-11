#include <iostream>

using namespace std;

int dx[] = { 0, 1 };
int dy[] = { 1, 0 };

int N;
bool endCheck = false;
int board[3][3];
bool check[3][3];

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

void DFS(int x, int y, int cnt)
{
	if (endCheck)
	{
		return;
	}

	if (x == N - 1 && y == N - 1)
	{
		endCheck = true;
		cout << "HaruHaru\n";
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		int nx = x + dx[i] * cnt;
		int ny = y + dy[i] * cnt;

		if (InRange(nx, ny) && !check[nx][ny])
		{
			check[x][y] = true;
			DFS(nx, ny, board[nx][ny]);
			check[x][y] = false;
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	check[0][0] = true;
	DFS(0, 0, board[0][0]);

	if (!endCheck)
	{
		cout << "Hing\n";
	}

	return 0;
}