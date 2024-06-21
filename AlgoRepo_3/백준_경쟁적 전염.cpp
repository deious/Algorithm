#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int N, K, S, X, Y;
int board[200][200];
queue<tuple<int, int, int, int>> q;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

void BFS()
{
	while (!q.empty())
	{
		int num = get<0>(q.front());
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		int cnt = get<3>(q.front());
		q.pop();

		if (cnt >= S)
		{
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && board[nx][ny] == 0)
			{
				board[nx][ny] = num;
				q.push({ num, nx, ny, cnt + 1 });
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<tuple<int, int, int>> v;

	int temp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			board[i][j] = temp;
			if (temp != 0)
			{
				v.push_back({ temp ,i, j });
			}
		}
	}

	cin >> S >> X >> Y;

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		q.push({ get<0>(v[i]), get<1>(v[i]) , get<2>(v[i]) , 0 });
	}

	BFS();

	cout << board[X - 1][Y - 1] << "\n";

	return 0;
}