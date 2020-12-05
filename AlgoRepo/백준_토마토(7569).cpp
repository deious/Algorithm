#include<iostream>
#include<queue>

using namespace std;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int n, m, h, ans;
int arr[101][101][101];
bool visit[101][101][101];
bool check;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n >> h;

	queue <pair <pair<int, int>, pair<int, int>>> q;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> arr[i][j][k];

				if (arr[i][j][k] == 1)
				{
					visit[i][j][k] = true;
					q.push(make_pair(make_pair(j, k), make_pair(i, 0)));
				}
				else if (!check && arr[i][j][k] == 0) check = true;
			}
		}
	}

	if (!check)
	{
		cout << "0\n";
		return 0;
	}

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second.first;
		ans = q.front().second.second;

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (arr[nz][nx][ny] == 0 && !visit[nz][nx][ny])
			{
				visit[nz][nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny), make_pair(nz, ans + 1)));
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (arr[i][j][k] == 0 && !visit[i][j][k])
				{
					ans = -1;
					break;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}