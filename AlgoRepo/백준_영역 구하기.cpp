#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int board[101][101];
bool check[101][101];

int M, N;

vector<int> v;

bool InRange(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	check[x][y] = true;
	int area = 0;

	while (!q.empty())
	{
		area++;
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (InRange(nx, ny) && !board[nx][ny] && !check[nx][ny])
			{
				check[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	v.push_back(area);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K, x1, y1, x2, y2;
	cin >> M >> N >> K;

	while (K--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				board[i][j] = 1;
				check[i][j] = true;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!board[i][j] && !check[i][j])
				BFS(i, j);
		}
	}

	sort(v.begin(), v.end());
	int len = v.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++)
		cout << v[i] << " ";

	return 0;
}