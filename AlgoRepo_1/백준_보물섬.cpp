#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[50][50];
bool check[50][50];
int n, m;

bool InRange(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int BFS(int x, int y)
{
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(x, y, 0));

	int dist = 0;
	while (!q.empty())
	{
		x = get<0>(q.front());
		y = get<1>(q.front());
		dist = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] == 'L')
			{
				check[nx][ny] = true;
				q.push(make_tuple(nx, ny, dist + 1));
			}
		}
	}

	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int ans = 0, maxNum;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'L')
			{
				check[i][j] = true;
				maxNum = BFS(i, j);
				ans = max(ans, maxNum);
				memset(check, false, sizeof(check));
			}
		}
	}

	cout << ans << "\n";

	return 0;
}