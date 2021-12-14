#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

char board[5][9];

int startPinCount, startMoveCount;

bool InRange(int x, int y)
{
	return x >= 0 && x < 5 && y >= 0 && y < 9;
}

void DFS(int move, int pinCount)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 'o')
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (InRange(nx, ny) && board[nx][ny] == 'o')
					{
						int nnx = nx + dx[k];
						int nny = ny + dy[k];

						if (InRange(nnx, nny) && board[nnx][nny] == '.')
						{
							board[i][j] = '.';
							board[nx][ny] = '.';
							board[nnx][nny] = 'o';
							DFS(move + 1, pinCount - 1);
							board[i][j] = 'o';
							board[nx][ny] = 'o';
							board[nnx][nny] = '.';
						}
					}
				}
			}
		}
	}

	if (pinCount <= startPinCount)
	{
		if (pinCount == startPinCount)
			startMoveCount = min(startMoveCount, move);
		else
			startMoveCount = move;

		startPinCount = pinCount;
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	while (N--)
	{
		int pin = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == 'o')
					pin++;
			}
		}

		startPinCount = pin;
		startMoveCount = 2100000000;
		DFS(0, pin);

		cout << startPinCount << " " << startMoveCount << "\n";
	}

	return 0;
}