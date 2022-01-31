#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int board[125][125];
int check[125][125];

int N;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

int BFS(int a, int b)
{
	queue<pair<int, int>> q;
	q.push({ a, b });
	check[a][b] = board[a][b];

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny))
			{
				if (check[nx][ny] > board[nx][ny] + check[x][y])
				{
					check[nx][ny] = board[nx][ny] + check[x][y];
					q.push({ nx, ny });
				}
			}
		}
	}

	return check[N - 1][N - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int answer = 0, num = 0;
	while (cin >> N)
	{
		if (!N)
			break;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
				check[i][j] = 210000000;
			}
		}

		answer = BFS(0, 0);
		num++;
		cout << "Problem " << num << ": " << answer << "\n";
	}

	return 0;
}