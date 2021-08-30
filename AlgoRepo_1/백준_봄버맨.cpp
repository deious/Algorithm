#include <iostream>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[200][200];
int boomTimer[200][200];

int R, C, N, cntTime = 0;

bool InRange(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

void BoomInstall()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == '.')
			{
				board[i][j] = 'O';
				boomTimer[i][j] = cntTime + 3;
			}
		}
	}

	return;
}

void Explosion(int time)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (boomTimer[i][j] == time)
			{
				board[i][j] = '.';
				boomTimer[i][j] = 0;

				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (InRange(nx, ny) && boomTimer[nx][ny] != time)
					{
						board[nx][ny] = '.';
						boomTimer[nx][ny] = 0;
					}
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

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'O')
				boomTimer[i][j] = 3;
		}
	}

	cntTime = 1;
	while (N != cntTime)
	{
		cntTime++;
		if (cntTime % 2 == 0)
			BoomInstall();
		else
			Explosion(cntTime);
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}

	return 0;
}