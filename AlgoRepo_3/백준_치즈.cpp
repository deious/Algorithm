#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int N, M;
int board[100][100];
int countBoard[100][100];
bool check[100][100];

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = true;

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (InRange(nx, ny) && !check[nx][ny])
			{
				if (board[nx][ny] == 0)
				{
					check[nx][ny] = true;
					q.push({ nx, ny });
				}
				else if (board[nx][ny] == 1)
				{
					countBoard[nx][ny]++;
				}
			}
		}
	}

	return;
}

void ChangeBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (countBoard[i][j] >= 2)
			{
				board[i][j] = 0;
			}
		}
	}
}

bool CheckBaord()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 1)
			{
				return false;
			}
		}
	}

	return true;
}

void CheckInit()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			check[i][j] = false;
			countBoard[i][j] = 0;
		}
	}
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

	bool endCheck = false;
	int ans = 0;
	endCheck = CheckBaord();

	while (!endCheck)
	{
		BFS(0, 0);
		ChangeBoard();
		CheckInit();
		ans++;
		endCheck = CheckBaord();
	}

	cout << ans << "\n";

	return 0;
}