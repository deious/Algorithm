#include <iostream>
#include <queue>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int board[1000][1000];
bool check[1000][1000];
int N, M;
bool endCheck = false;

bool InRange(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty())
	{
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		if (tx == M - 1)
		{
			cout << "YES\n";
			endCheck = true;
			break;
		}

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

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N;

	string s;
	for (int i = 0; i < M; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
		{
			board[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (!check[0][i] && board[0][i] == 0)
		{
			BFS(0, i);
			if (endCheck)
			{
				return 0;
			}
		}
	}

	cout << "NO\n";

	return 0;
}