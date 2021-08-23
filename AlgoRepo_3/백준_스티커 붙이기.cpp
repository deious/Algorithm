#include <iostream>
#include <cstring>

using namespace std;

int N, M, K;

int board[41][41];
int sticker[10][10];

bool InRange(int x, int y)
{
	return x > 0 && x <= N && y > 0 && y <= M;
}

void attach(int a, int b, int row, int col)
{
	for (int i = a; i < row + a; i++)
	{
		for (int j = b; j < col + b; j++)
		{
			if (!board[i][j])
				board[i][j] = sticker[i - a][j - b];
		}
	}

	return;
}

void rotate(int row, int col)
{
	int temp[10][10];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp[i][j] = sticker[i][j];

	memset(sticker, 0, sizeof(sticker));
										 
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			sticker[i][j] = temp[row - j - 1][i];

	return;
}

bool attempt(int x, int y, int count)
{
	if (count == 4) 
		return false;

	bool possible = false;

	if (InRange(x, y))
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				possible = true;
				if (InRange(x + i, y + j))
				{
					for (int k = 0; k < x; k++)
					{
						for (int l = 0; l < y; l++)
						{
							if (sticker[k][l] == 1 && board[k + i][l + j] == 1)
							{
								possible = false;
								break;
							}
						}
						if (!possible)
							break;
					}
				}
				else
					possible = false;

				if (possible)
				{
					attach(i, j, x, y);
					return true;
				}
			}
		}
	}


	if (!possible)
	{
		rotate(x, y);
		if (attempt(y, x, count + 1))
			return true;
		else
			return false;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	int x, y;
	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;

		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				cin >> sticker[i][j];

		attempt(x, y, 0);
	}
	int ans = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j])
				ans++;

	cout << ans << "\n";

	return 0;
}