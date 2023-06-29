#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int board[101][101];
bool light[101][101];
bool check[101][101];

vector<pair<int, int>> v[101][101];

int N, M;

bool InRange(int x, int y)
{
	return x > 0 && x <= N && y > 0 && y <= N;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int x, y, a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> a >> b;
		v[x][y].push_back({ a, b });
	}

	int answer = 1;

	while (true)
	{
		memset(check, false, sizeof(check));
		queue<pair<int, int>> q;
		q.push({ 1,1 });
		light[1][1] = true;
		check[1][1] = true;
		bool flag = false;

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (!v[x][y].empty())
			{
				for (int i = 0; i < v[x][y].size(); i++)
				{
					int tx = v[x][y][i].first;
					int ty = v[x][y][i].second;
					if (!light[tx][ty])
					{
						answer++;
						light[tx][ty] = true;
					}
				}
				v[x][y].clear();
				flag = true;
			}

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (InRange(nx, ny) && !check[nx][ny] && light[nx][ny])
				{
					check[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}

		if (!flag)
			break;
	}

	cout << answer << "\n";

	return 0;
}