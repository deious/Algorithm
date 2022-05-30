#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int board[500][500];
bool check[500][500];

int area = 0, maxSize = 0;
int N, M;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

void BFS(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({ a, b });
	check[a][b] = true;
	int areaSize = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] == 1)
			{
				q.push({ nx, ny });
				check[nx][ny] = true;
				areaSize++;
			}
		}
	}

	if (areaSize > maxSize)
		maxSize = areaSize;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!check[i][j] && board[i][j] == 1)
			{
				BFS(i, j);
				area++;
			}
		}
	}

	cout << area << "\n" << maxSize << "\n";

	return 0;
}