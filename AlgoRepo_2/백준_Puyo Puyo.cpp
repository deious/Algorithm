#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

char board[12][6];
bool check[12][6];

int ans = 0;
bool chainCheck = false;
bool totalCheck = false;

bool InRange(int x, int y)
{
	return x >= 0 && x < 12 && y >= 0 && y < 6;
}

void movePuyo()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 10; j >= 0; j--)
		{
			if (board[j][i] != '.')
			{
				for (int k = 11; k > j; k--)
				{
					if (board[k][i] == '.')
					{
						board[k][i] = board[j][i];
						board[j][i] = '.';
						break;
					}
				}
			}
		}
	}
	totalCheck = true;
}

void chain(int a, int b, char c)
{
	int chainCount = 1;
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;

	q.push(make_pair(a, b));
	v.push_back(make_pair(a, b));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !check[nx][ny] && board[nx][ny] == c)
			{
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
				v.push_back(make_pair(nx, ny));
				chainCount++;
			}
		}
	}

	if (chainCount >= 4)
	{
		int len = v.size();
		for (int i = 0; i < len; i++)
			board[v[i].first][v[i].second] = '.';

		chainCheck = true;
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> board[i][j];

	while (1)
	{
		totalCheck = false;

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (!check[i][j] && board[i][j] != '.')
				{
					check[i][j] = true;
					chain(i, j, board[i][j]);
				}
			}
		}

		if (chainCheck)
		{
			ans++;
			chainCheck = false;
			movePuyo();
		}

		if (!totalCheck)
			break;

		memset(check, false, sizeof(check));
	}

	cout << ans << "\n";

	return 0;
}
