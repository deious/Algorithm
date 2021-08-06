#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int lab[50][50];
int N, M;

bool check[50][50];

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	vector<pair<int, int>> v;

	int zeroCount = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> lab[i][j];

			if (lab[i][j] == 2)
				v.push_back(make_pair(i, j));
			else if (!lab[i][j])
				zeroCount++;
		}
	}

	int len = v.size();

	vector<int> v1(len);

	for (int i = 0; i < M; i++)
		v1[i] = 1;

	len = v1.size();
	int ans = 2100000000;

	do
	{
		queue<tuple<int, int, int>> q;
		memset(check, false, sizeof(check));

		int tempCount = 0;
		for (int i = 0; i < len; i++)
		{
			if (v1[i])
			{
				q.push(make_tuple(v[i].first, v[i].second, 0));
				check[v[i].first][v[i].second] = true;
			}
		}

		while (!q.empty())
		{
			int x = get<0>(q.front());
			int y = get<1>(q.front());
			int time = get<2>(q.front());
			q.pop();

			if (zeroCount == tempCount)
			{
				if (!q.empty())
					ans = min(ans, get<2>(q.back()));
				else
					ans = min(ans, time);

				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (InRange(nx, ny) && !check[nx][ny] && (!lab[nx][ny] || lab[nx][ny] == 2))
				{
					if (!lab[nx][ny])
						tempCount++;

					check[nx][ny] = true;
					q.push(make_tuple(nx, ny, time + 1));
				}
			}
		}
	} while (prev_permutation(v1.begin(), v1.end()));

	if (ans == 2100000000)
		cout << "-1\n";
	else
		cout << ans << "\n";

	return 0;
}