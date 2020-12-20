#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m, ans = 0;
int rebo[8][8];
int tempRebo[8][8];
bool check[8][8];

queue<pair<int, int>> que;

void wallCheck(int x, int y, int count)
{
	int tempMax = 0;

	if (count == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				tempRebo[i][j] = rebo[i][j];
			}
		}

		queue<pair<int, int>> q = que;

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

				if (tempRebo[nx][ny] == 1 || tempRebo[nx][ny] == 2 || check[nx][ny] || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

				q.push(make_pair(nx, ny));
				tempRebo[nx][ny] = 2;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tempRebo[i][j] == 0) tempMax++;
			}
		}

		ans = max(ans, tempMax);
		memset(check, false, sizeof(check));
		return;
	}

	for (int i = x; i < n; i++)
	{
		if (i == x + 1 && y != 0) y = 0;

		for (int j = y; j < m; j++)
		{
			if (rebo[i][j] == 0)
			{
				rebo[i][j] = 1;
				wallCheck(i, j, count + 1);
				rebo[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> rebo[i][j];
			if (rebo[i][j] == 2) que.push(make_pair(i, j));
		}
	}

	wallCheck(0, 0, 0);

	cout << ans << "\n";

	return 0;
}