#include <iostream>
#include <queue>

using namespace std;

int board[20][20];
int dice[6] = { 0, 0, 0, 0, 0, 0 };

int N, M, x, y, K;

bool InRange(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> x >> y >> K;

	queue<int> q;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;
		q.push(num);
	}

	while (!q.empty())
	{
		int n = q.front();
		int temp;
		q.pop();

		if (n == 1)
		{
			if (InRange(x, y + 1))
			{
				y++;
				temp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[3];
				dice[3] = dice[5];
				dice[5] = temp;

				if (board[x][y] == 0)
				{
					board[x][y] = dice[2];
				}
				else
				{
					dice[2] = board[x][y];
					board[x][y] = 0;
				}

				cout << dice[5] << "\n";
			}
		}
		else if (n == 2)
		{
			if (InRange(x, y - 1))
			{
				y--;
				temp = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[3];
				dice[3] = dice[2];
				dice[2] = temp;

				if (board[x][y] == 0)
				{
					board[x][y] = dice[2];
				}
				else
				{
					dice[2] = board[x][y];
					board[x][y] = 0;
				}

				cout << dice[5] << "\n";
			}
		}
		else if (n == 3)
		{
			if (InRange(x - 1, y))
			{
				x--;
				temp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[5];
				dice[5] = temp;

				if (board[x][y] == 0)
				{
					board[x][y] = dice[2];
				}
				else
				{
					dice[2] = board[x][y];
					board[x][y] = 0;
				}

				cout << dice[5] << "\n";
			}
		}
		else
		{
			if (InRange(x + 1, y))
			{
				x++;
				temp = dice[0];
				dice[0] = dice[5];
				dice[5] = dice[4];
				dice[4] = dice[2];
				dice[2] = temp;

				if (board[x][y] == 0)
				{
					board[x][y] = dice[2];
				}
				else
				{
					dice[2] = board[x][y];
					board[x][y] = 0;
				}

				cout << dice[5] << "\n";
			}
		}
	}

	return 0;
}