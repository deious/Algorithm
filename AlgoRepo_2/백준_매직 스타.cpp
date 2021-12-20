#include <iostream>
#include <vector>

using namespace std;

char board[5][9];
bool alpha[13];

int xCount = 0;

vector<pair<int, int>> v;

bool Calculate()
{
	if (board[0][4] - 64 + board[1][3] - 64 + board[2][2] - 64 + board[3][1] - 64 != 26)
		return false;
	if (board[0][4] - 64 + board[1][5] - 64 + board[2][6] - 64 + board[3][7] - 64 != 26)
		return false;
	if (board[1][1] - 64 + board[1][3] - 64 + board[1][5] - 64 + board[1][7] - 64 != 26)
		return false;
	if (board[1][1] - 64 + board[2][2] - 64 + board[3][3] - 64 + board[4][4] - 64 != 26)
		return false;
	if (board[1][7] - 64 + board[2][6] - 64 + board[3][5] - 64 + board[4][4] - 64 != 26)
		return false;
	if (board[3][1] - 64 + board[3][3] - 64 + board[3][5] - 64 + board[3][7] - 64 != 26)
		return false;

	return true;
}

void DFS(int index, int current)
{
	if (current == xCount)
	{
		if (Calculate())
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					cout << board[i][j];
				}
				cout << "\n";
			}
			
			exit(0);
		}
	}

	for (int i = 1; i < 13; i++)
	{
		if (alpha[i])
			continue;
		alpha[i] = true;
		board[v[index].first][v[index].second] = 'A' + i - 1;
		DFS(index + 1, current + 1);
		board[v[index].first][v[index].second] = 'x';
		alpha[i] = false;
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	alpha[0] = true;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != '.')
			{
				if (board[i][j] == 'x')
				{
					v.push_back({ i, j });
					xCount++;
				}
				else
					alpha[board[i][j] - 64] = true;
			}
		}
	}

	DFS(0, 0);

	return 0;
}