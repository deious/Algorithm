#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

bool board[50][50];
bool check[50][50];

int answer = 0;

int M, N;

bool InRange(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}

void BFS(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i, j });
	check[i][j] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] == 1)
			{
				check[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, K;
	cin >> T;

	while (T--)
	{
		cin >> M >> N >> K;
		
		memset(board, 0, sizeof(board));
		memset(check, false, sizeof(check));

		int a, b;
		answer = 0;
		for (int i = 0; i < K; i++)
		{
			cin >> a >> b;
			board[a][b] = 1;
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == 1 && !check[i][j])
				{
					BFS(i, j);
					answer++;
				}
			}
		}

		cout << answer << "\n";
	}

	return 0;
}