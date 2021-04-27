#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int board[1000][1000];
queue<pair<int, int>> q[10];
int answer[10];
int moveDistance[10];
int N, M, P;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

void BFS(int num)
{
	int mLen = moveDistance[num];
	for (int i = 0; i < mLen; i++)
	{
		int len = q[num].size();
		if (!len)
			return;

		while (len--)
		{
			int x = q[num].front().first;
			int y = q[num].front().second;
			q[num].pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (InRange(nx, ny) && !board[nx][ny])
				{
					board[nx][ny] = num;
					answer[num]++;
					q[num].push(make_pair(nx, ny));
				}
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> P;

	int temp;
	for (int i = 1; i <= P; i++)
		cin >> moveDistance[i];

	string s;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		int len = s.size();
		for (int j = 0; j < len; j++)
		{
			if (s[j] - '0' > 0 && s[j] - '0' < 10)
			{
				board[i][j] = s[j] - '0';
				q[board[i][j]].push(make_pair(i, j));
				answer[board[i][j]]++;
			}
			else if (s[j] == '#')
				board[i][j] = 35;
			else
				board[i][j] = 0;
		}
	}

	while (true)
	{
		int checkCount = 0;
		for (int i = 1; i <= P; i++)
		{
			if (!q[i].empty())
				BFS(i);
			else
				checkCount++;
		}
		if (checkCount == P)
			break;
	}

	for (int i = 1; i <= P; i++)
		cout << answer[i] << " ";
	cout << "\n";

	return 0;
}