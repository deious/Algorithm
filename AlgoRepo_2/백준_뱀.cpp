#include <iostream>
#include <queue>

using namespace std;

int board[102][102];
bool boardCheck[102][102];
bool apple[102][102];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int N;

bool InRange(int x, int y)
{
	return x >= 1 && x <= N && y >= 1 && y <= N;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K, x, y, time = 0;
	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		apple[x][y] = true;
	}
	cin >> K;
	queue<pair<int, char>> q;
	queue<pair<int, int>> tailPos;
	tailPos.push(make_pair(1, 1));
	char c;

	for (int i = 0; i < K; i++)
	{
		cin >> x >> c;
		q.push(make_pair(x, c));
	}
	x = 1, y = 1;
	int dt, tx, ty, i = 0;
	char dc;
	boardCheck[1][1] = true;
	while (true)
	{
		dt = q.front().first;
		dc = q.front().second;
		q.pop();

		while (true)
		{
			time++;
			int nx = x + dx[i % 4];
			int ny = y + dy[i % 4];

			if (!InRange(nx, ny) || boardCheck[nx][ny])
			{
				cout << time << "\n";
				return 0;
			}

			if (apple[nx][ny])
			{
				apple[nx][ny] = false;
				boardCheck[nx][ny] = true;
			}
			else
			{
				boardCheck[nx][ny] = true;
				tx = tailPos.front().first;
				ty = tailPos.front().second;
				boardCheck[tx][ty] = false;
				tailPos.pop();
			}

			tailPos.push(make_pair(nx, ny));
			x = nx, y = ny;

			if (time == dt)
			{
				if (dc == 'L')
					i += 3;
				else
					i++;
				break;
			}
		}
	}

	return 0;
}