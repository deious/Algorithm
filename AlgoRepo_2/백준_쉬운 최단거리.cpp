#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int board[1000][1000];
int dist[1000][1000];
bool check[1000][1000];

int n, m;

bool InRange(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

void BFS(int a, int b)
{
	queue<tuple<int, int, int>> q;
	check[a][b] = true;
	q.push({ a, b, 0 });

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int move = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] == 1)
			{
				check[nx][ny] = true;
				dist[nx][ny] = move + 1;
				q.push({ nx, ny, move + 1 });
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	
	int sx, sy;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				sx = i;
				sy = j;
			}
		}
	}

	BFS(sx, sy);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && dist[i][j] == 0)
			{
				dist[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}