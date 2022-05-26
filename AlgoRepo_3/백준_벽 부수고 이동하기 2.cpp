#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

char board[1001][1001];
bool check[1001][1001][11];

int N, M, K;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

void BFS()
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { 0, 0 }, { 1, 0 } });
	check[0][0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int moveCount = q.front().second.first;
		int wallCount = q.front().second.second;
		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			cout << moveCount << "\n";
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny))
			{
				if (board[nx][ny] == '0' && !check[nx][ny][wallCount])
				{
					check[nx][ny][wallCount] = true;
					q.push({ {nx, ny}, {moveCount + 1, wallCount} });
				}
				else if (board[nx][ny] == '1' && wallCount < K && !check[nx][ny][wallCount + 1])
				{
					check[nx][ny][wallCount + 1] = true;
					q.push({ { nx, ny }, { moveCount + 1, wallCount + 1} });
				}
			}
		}
	}

	cout << "-1\n";

	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	BFS();

	return 0;
}