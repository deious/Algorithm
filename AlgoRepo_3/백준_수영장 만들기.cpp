#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int board[52][52];

int N, M;

bool InRagne(int x, int y)
{
	return x >= 0 && x <= N + 1 && y >= 0 && y <= M + 1;
}

void BFS(int h)
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	bool check[52][52];
	memset(check, false, sizeof(check));
	check[0][0] = true;
	board[0][0] = h;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRagne(nx, ny) && !check[nx][ny] && board[nx][ny] < h)
			{
				q.push({ nx, ny });
				check[nx][ny] = true;
				board[nx][ny] = h;
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	int maxNum = 0;
	char c;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> c;
			board[i][j] = c - '0';
			if (board[i][j] > maxNum)
				maxNum = board[i][j];
		}
	}

	int answer = 0;
	for (int i = 1; i <= maxNum; i++)
	{
		BFS(i);
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= M; k++)
			{
				if (board[j][k] < i)
					answer++;
			}
		}
	}

	cout << answer << "\n";

	return 0;
}