#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
	int x, y;
};

char board[6][6];

int N;

vector<info> T;
vector<info> X;

bool Sight()
{
	int tLen = T.size();

	while (tLen--)
	{
		int x = T[tLen].x;
		int y = T[tLen].y;

		for (int i = y; i < N; i++)
		{
			if (board[x][i] == 'O')
				break;
			else if (board[x][i] == 'S')
				return false;
		}
		
		for (int i = y; i >= 0; i--)
		{
			if (board[x][i] == 'O')
				break;
			else if (board[x][i] == 'S')
				return false;
		}
		
		
		for (int i = x; i < N; i++)
		{
			if (board[i][y] == 'O')
				break;
			else if (board[i][y] == 'S')
				return false;
		}
		
		for (int i = x; i >= 0; i--)
		{
			if (board[i][y] == 'O')
				break;
			else if (board[i][y] == 'S')
				return false;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'T')
				T.push_back({ i, j });
			else if (board[i][j] == 'X')
				X.push_back({ i, j });
		}
	}

	int len = X.size();
	int tLen = T.size();
	vector<int> v(len);

	for (int i = 0; i < 3; i++)
		v[i] = 1;

	bool check = false;
	do
	{
		check = false;
		vector<info> save;

		for (int i = 0; i < len; i++)
		{
			if (v[i])
			{
				int x = X[i].x;
				int y = X[i].y;
				save.push_back({ x, y });

				board[x][y] = 'O';
			}
		}

		check = Sight();
		if (check)
		{
			cout << "YES\n";
			return 0;
		}
		else
		{
			for (int i = 0; i < save.size(); i++)
			{
				int x = save[i].x;
				int y = save[i].y;
				board[x][y] = 'X';
			}
		}

	} while (prev_permutation(v.begin(), v.end()));

	if (!check)
		cout << "NO\n";

	return 0;
}