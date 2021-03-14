#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char board[10][10];
bool check[10][10][10][10];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, M;
queue<tuple<int, int ,int, int, int>> q;

void Move(int &x, int &y, int &mc, int dx, int dy)
{
	while (board[x + dx][y + dy] != '#' && board[x][y] != 'O')
	{
		x += dx;
		y += dy;
		mc++;
	}

	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int rx, ry, bx, by;
	bool exitCheck = false;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'R')
			{
				rx = i;
				ry = j;
			}

			if (board[i][j] == 'B')
			{
				bx = i;
				by = j;
			}
		}

	q.push(make_tuple(rx, ry, bx, by, 0));
	check[rx][ry][bx][by] = true;

	while (!q.empty())
	{
		rx = get<0>(q.front());
		ry = get<1>(q.front());
		bx = get<2>(q.front());
		by = get<3>(q.front());
		int mCount = get<4>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int rnx = rx, rny = ry, bnx = bx, bny = by;
			int rmc = 0, bmc = 0, nc = mCount + 1;
			
			Move(rnx, rny, rmc, dx[i], dy[i]);
			Move(bnx, bny, bmc, dx[i], dy[i]);

			if (board[bnx][bny] == 'O')
				continue;
			if (board[rnx][rny] == 'O')
			{
				cout << nc << "\n";
				exitCheck = true;
				break;
			}

			if (rnx == bnx && rny == bny)
			{
				if (rmc > bmc)
				{
					rnx -= dx[i];
					rny -= dy[i];
				}
				else
				{
					bnx -= dx[i];
					bny -= dy[i];
				}
			}

			if (!check[rnx][rny][bnx][bny])
			{
				check[rnx][rny][bnx][bny] = true;
				q.push(make_tuple(rnx, rny, bnx, bny, nc));
			}
		}

		if (exitCheck)
			break;
	}

	if (!exitCheck)
		cout << -1 << "\n";

	return 0;
}