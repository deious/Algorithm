#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N;
int board[10][10];
bool check[10][10][101][3];

int nkx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int nky[] = {2, 2, 1, -1, -2, -2, -1, 1};

int nbx[] = {-1, 1, 1, -1};
int nby[] = {1, 1, -1, -1};

int nrx[] = {0, 1, 0, -1};
int nry[] = {1, 0, -1, 0};

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < N;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	queue<tuple<int, int, int, int, int>> q;

	int M;
	M = N * N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				for (int k = 0; k < 3; k++)
				{
					check[i][j][1][k] = true;
					q.push(make_tuple(i, j, k, 0, 1));
				}
			}
		}
	}

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int chessPiece = get<2>(q.front());
		int moveCount = get<3>(q.front());
		int currentNum = get<4>(q.front());
		q.pop();

		if (currentNum == M)
		{
			cout << moveCount << "\n";
			return 0;
		}

		for (int k = 0; k < 3; k++)
		{
			if (chessPiece == k)
				continue;
			if (check[x][y][currentNum][k])
				continue;

			check[x][y][currentNum][chessPiece] = true;
			q.push(make_tuple(x, y, k, moveCount + 1, currentNum));
		}

		if (chessPiece == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = x + nkx[i];
				int ny = y + nky[i];

				if (InRange(nx, ny))
				{
					if (board[nx][ny] == currentNum + 1 && !check[nx][ny][currentNum + 1][0])
					{
						check[nx][ny][currentNum + 1][0] = true;
						q.push(make_tuple(nx, ny, 0, moveCount + 1, currentNum + 1));
					}
					else if (!check[nx][ny][currentNum][0])
					{
						check[nx][ny][currentNum][0] = true;
						q.push(make_tuple(nx, ny, 0, moveCount + 1, currentNum));
					}
				}
			}
		}
		else if (chessPiece == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 1; ; j++)
				{
					int nx = x + nbx[i] * j;
					int ny = y + nby[i] * j;

					if (InRange(nx, ny))
					{
						if (board[nx][ny] == currentNum + 1 && !check[nx][ny][currentNum + 1][1])
						{
							check[nx][ny][currentNum + 1][1] = true;
							q.push(make_tuple(nx, ny, 1, moveCount + 1, currentNum + 1));
						}
						else if (!check[nx][ny][currentNum][1])
						{
							check[nx][ny][currentNum][1] = true;
							q.push(make_tuple(nx, ny, 1, moveCount + 1, currentNum));
						}
					}
					else
						break;
				}
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 1; ; j++)
				{
					int nx = x + nrx[i] * j;
					int ny = y + nry[i] * j;

					if (InRange(nx, ny))
					{
						if (board[nx][ny] == currentNum + 1 && !check[nx][ny][currentNum + 1][2])
						{
							check[nx][ny][currentNum + 1][2] = true;
							q.push(make_tuple(nx, ny, 2, moveCount + 1, currentNum + 1));
						}
						else if (!check[nx][ny][currentNum][2])
						{
							check[nx][ny][currentNum][2] = true;
							q.push(make_tuple(nx, ny, 2, moveCount + 1, currentNum));
						}
					}
					else
						break;
				}
			}

		}
	}

	return 0;
}