#include <iostream>
#include <algorithm>

using namespace std;

int board[10][10];
int confetti[6];
int answer = 2100000000;

bool InRange(int x, int y)
{
	return x >= 0 && x < 10 && y >= 0 && y < 10;
}

void Cover(int x, int y, int size)
{
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			board[i][j] = 0;
		}
	}
}

void UnCover(int x, int y, int size)
{
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			board[i][j] = 1;
		}
	}
}

bool CoverCheck(int x, int y, int size)
{
	if (!InRange(x + size - 1, y + size - 1))
	{
		return false;
	}

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (board[i][j] == 0)
			{
				return false;
			}
		}
	}

	return true;
}

void BackTracking(int x, int y, int cnt)
{
	if (x > 9)
	{
		answer = min(answer, cnt);
		return;
	}

	if (answer <= cnt)
	{
		return;
	}

	if (y > 9)
	{
		BackTracking(x + 1, 0, cnt);
		return;
	}

	if (board[x][y] == 1)
	{
		for (int i = 5; i >= 1; i--)
		{
			if (confetti[i] > 0 && CoverCheck(x, y, i))
			{
				confetti[i]--;
				Cover(x, y, i);
				BackTracking(x, y + 1, cnt + 1);
				UnCover(x, y, i);
				confetti[i]++;
			}
		}
	}
	else
	{
		BackTracking(x, y + 1, cnt);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= 5; i++)
	{
		confetti[i] = 5;
	}

	BackTracking(0, 0, 0);

	if (answer == 2100000000)
	{
		answer = -1;
	}

	cout << answer << "\n";

	return 0;
}