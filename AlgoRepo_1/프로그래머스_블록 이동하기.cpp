#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

bool check[100][100][2];
int N;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

int solution(vector<vector<int>> board) {
	N = board.size();
	queue<tuple<int, int, int, int, int, int>> q;
	q.push({ 0, 0, 0, 1, 0, 0 });
	check[0][0][0] = true;
	check[0][1][0] = true;

	while (!q.empty())
	{
		int x1 = get<0>(q.front());
		int y1 = get<1>(q.front());
		int x2 = get<2>(q.front());
		int y2 = get<3>(q.front());
		int status = get<4>(q.front());
		int time = get<5>(q.front());
		q.pop();

		if ((x1 == N - 1 && y1 == N - 1) || (x2 == N - 1 && y2 == N - 1))
			return time;

		for (int i = 0; i < 4; i++)
		{
			int nx1 = x1 + dx[i];
			int ny1 = y1 + dy[i];
			int nx2 = x2 + dx[i];
			int ny2 = y2 + dy[i];

			if (InRange(nx1, ny1) && InRange(nx2, ny2) && board[nx1][ny1] == 0 && board[nx2][ny2] == 0 && (!check[nx1][ny1][status] || !check[nx2][ny2][status]))
			{
				check[nx1][ny1][status] = true;
				check[nx2][ny2][status] = true;
				q.push({ nx1, ny1, nx2, ny2, status, time + 1 });
			}
		}

		if (status == 0)
		{
			if (InRange(x1 - 1, y1) && board[x1 - 1][y1] == 0)
			{
				if (board[x2 - 1][y2] == 0 && (!check[x1 - 1][y1][1] || !check[x1][y1][1]))
				{
					check[x1 - 1][y1][1] = true;
					check[x1][y1][1] = true;
					q.push({ x1 - 1, y1, x1, y1, 1, time + 1 });
				}
			}

			if (InRange(x1 + 1, y1) && board[x1 + 1][y1] == 0)
			{
				if (board[x2 + 1][y2] == 0 && (!check[x1 + 1][y1][1] || !check[x1][y1][1]))
				{
					check[x1 + 1][y1][1] = true;
					check[x1][y1][1] = true;
					q.push({ x1, y1, x1 + 1, y1, 1, time + 1 });
				}
			}

			if (InRange(x2 - 1, y2) && board[x2 - 1][y2] == 0)
			{
				if (board[x1 - 1][y1] == 0 && (!check[x2 - 1][y2][1] || !check[x2][y2][1]))
				{
					check[x2 - 1][y2][1] = true;
					check[x2][y2][1] = true;
					q.push({ x2 - 1, y2, x2, y2, 1, time + 1 });
				}
			}

			if (InRange(x2 + 1, y2) && board[x2 + 1][y2] == 0)
			{
				if (board[x1 + 1][y1] == 0 && (!check[x2 + 1][y2][1] || !check[x2][y2][1]))
				{
					check[x2 + 1][y2][1] = true;
					check[x2][y2][1] = true;
					q.push({ x2, y2, x2 + 1, y2, 1, time + 1 });
				}
			}
		}
		else
		{
			if (InRange(x1, y1 + 1) && board[x1][y1 + 1] == 0)
			{
				if (board[x2][y2 + 1] == 0 && (!check[x1][y1 + 1][0] || !check[x1][y1][0]))
				{
					check[x1][y1 + 1][0] = true;
					check[x1][y1][0] = true;
					q.push({ x1, y1, x1, y1 + 1, 0, time + 1 });
				}
			}

			if (InRange(x1, y1 - 1) && board[x1][y1 - 1] == 0)
			{
				if (board[x2][y2 - 1] == 0 && (!check[x1][y1 - 1][0] || !check[x1][y1][0]))
				{
					check[x1][y1 - 1][0] = true;
					check[x1][y1][0] = true;
					q.push({ x1, y1 - 1, x1, y1, 0, time + 1 });
				}
			}

			if (InRange(x2, y2 + 1) && board[x2][y2 + 1] == 0)
			{
				if (board[x1][y1 + 1] == 0 && (!check[x2][y2 + 1][0] || !check[x2][y2][0]))
				{
					check[x2][y2 + 1][0] = true;
					check[x2][y2][0] = true;
					q.push({ x2, y2, x2, y2 + 1, 0, time + 1 });
				}
			}

			if (InRange(x2, y2 - 1) && board[x2][y2 - 1] == 0)
			{
				if (board[x1][y1 - 1] == 0 && (!check[x2][y2 - 1][0] || !check[x2][y2][0]))
				{
					check[x2][y2 - 1][0] = true;
					check[x2][y2][0] = true;
					q.push({ x2, y2 - 1, x2, y2, 0, time + 1 });
				}
			}
		}
	}
}