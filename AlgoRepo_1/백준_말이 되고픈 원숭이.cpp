#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int hx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int hy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };

bool check[200][200][31];
int K, W, H;

bool InRange(int x, int y)
{
	return x >= 0 && x < H && y >= 0 && y < W;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> K >> W >> H;

	vector<vector<int>> v(H, vector<int>(W));

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> v[i][j];

	queue<pair<pair<int, int>, pair<int, int>>> q;

	q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
 	check[0][0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int moveCount = q.front().second.first;
		int useCount = q.front().second.second;
		q.pop();

		if (x == H - 1 && y == W - 1)
		{
			cout << moveCount << "\n";
			return 0;
		}

		if (useCount < K)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = x + hx[i];
				int ny = y + hy[i];

				if (InRange(nx, ny) && !check[nx][ny][useCount + 1] && v[nx][ny] == 0)
				{
					check[nx][ny][useCount + 1] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(moveCount + 1, useCount + 1)));
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + mx[i];
			int ny = y + my[i];

			if (InRange(nx, ny) && !check[nx][ny][useCount] && v[nx][ny] == 0)
			{
				check[nx][ny][useCount] = true;
				q.push(make_pair(make_pair(nx, ny), make_pair(moveCount + 1, useCount)));
			}
		}
	}

	cout << -1 << "\n";

	return 0;
}