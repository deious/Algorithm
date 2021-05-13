#include <iostream>
#include <vector>

using namespace std;

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int board[101][101];
int N, x, y, d, g, ans = 0;

vector<int> dir;

void MakeDragon()
{
	int len = dir.size();

	for (int i = len - 1; i >= 0; i--)
	{
		int nDir = (dir[i] + 1) % 4;
		x += dx[nDir];
		y += dy[nDir];

		board[x][y] = 1;
		dir.push_back(nDir);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	while (N--)
	{
		cin >> y >> x >> d >> g;
		dir.clear();
		board[x][y] = 1;
		x += dx[d];
		y += dy[d];
		board[x][y] = 1;
		dir.push_back(d);

		for (int i = 0; i < g; i++)
			MakeDragon();
	}

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1)
				ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}