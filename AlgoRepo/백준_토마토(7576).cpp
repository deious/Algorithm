#include<iostream>
#include<queue>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int n, m, ans;
int arr[1001][1001];
bool visit[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	queue <pair <pair<int, int>, int>> q;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1)
			{
				visit[i][j] = true;
				q.push(make_pair(make_pair(i, j), 0));
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		ans = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n)	continue;
			if (arr[nx][ny] == 0 && !visit[nx][ny])
			{
				visit[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny), ans + 1));
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0 && !visit[i][j])
			{
				ans = -1;
				break;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}