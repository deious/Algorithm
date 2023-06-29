#include <iostream>
#include <queue>
#include <cstring> 

using namespace std;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int board[50][50];
bool check[50][50];

int n, m, roomSize = 0, maxArea = 0;

bool InRange(int x, int y) 
{
	return x >= 0 && x < m && y >= 0 && y < n;
}

void bfs(int x, int y) 
{
	int count = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) 
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		count++;

		for (int i = 0; i < 4; i++) 
		{
			if (((1 << i) & board[tx][ty]) == 0) 
			{
				int nx = tx + dx[i];
				int ny = ty + dy[i];

				if (!check[nx][ny] && InRange(nx, ny)) 
				{
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}

		}
	}

	roomSize++;

	if (count > maxArea)
		maxArea = count;
}

void breakWall(int x, int y) 
{
	for (int i = 0; i < 4; i++) 
	{
		if ((board[x][y] & (1 << i)) != 0)
		{
			memset(check, false, sizeof(check));
			board[x][y] = board[x][y] - (1 << i);
			check[x][y] = true;
			bfs(x, y);
			board[x][y] = board[x][y] + (1 << i);
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++) 
			cin >> board[i][j];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!check[i][j])
			{
				check[i][j] = true;
				bfs(i, j);
			}
		}
	}

	cout << roomSize << "\n";
	cout << maxArea << "\n";

	maxArea = 0;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			breakWall(i, j);

	cout << maxArea << "\n";

	return 0;
}
