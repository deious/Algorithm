#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char board[1001][1001];
bool check[1001][1001][11];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int N, M, K;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	queue<tuple<int, int, int, int, int>> q;
	q.push(make_tuple(0, 0, 1, 0, 0));
	check[0][0][0] = true;
	bool endCheck = false;

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int Count = get<2>(q.front());;
		int WallCount = get<3>(q.front());
		int day = get<4>(q.front());
		q.pop();

		if (x == N - 1 && y == M - 1)
		{
			cout << Count << "\n";
			endCheck = true;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny))
			{
				if (board[nx][ny] == '0')
				{
					if (!check[nx][ny][WallCount])
					{
						check[nx][ny][WallCount] = true;
						if(day == 0)
							q.push(make_tuple(nx, ny, Count + 1, WallCount, 1));
						else
							q.push(make_tuple(nx, ny, Count + 1, WallCount, 0));
					}
				}
				else if (board[nx][ny] == '1')
				{
					if (WallCount < K)
					{
						if (!check[nx][ny][WallCount + 1])
						{
							if (day == 0)
							{
								check[nx][ny][WallCount + 1] = true;
								q.push(make_tuple(nx, ny, Count + 1, WallCount + 1, 1));
							}
							else
								q.push(make_tuple(x, y, Count + 1, WallCount, 0));
						}
					}
				}
			}
		}
	}

	if(!endCheck)
		cout << "-1\n";

	return 0;
}