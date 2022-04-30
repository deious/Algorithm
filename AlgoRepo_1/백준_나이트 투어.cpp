#include <iostream>
#include <string>

using namespace std;

int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

bool board[6][6];

bool InRange(int x, int y)
{
	return x >= 0 && x < 6 && y >= 0 && y < 6;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int x, y, sx, sy;
	bool check = false;

	cin >> s;
	sx = x = abs((s[1] - '0') - 6);
	sy = y = s[0] - 'A';
	board[x][y] = true;

	for (int i = 0; i < 35; i++)
	{
		cin >> s;
		int tx = abs((s[1] - '0') - 6);
		int ty = s[0] - 'A';
		check = false;

		for (int j = 0; j < 8; j++)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (InRange(nx, ny) && !board[nx][ny] && nx == tx && ny == ty)
			{
				board[nx][ny] = true;
				check = true;
				x = nx;
				y = ny;
				break;
			}
		}

		if (!check)
		{
			cout << "Invalid\n";
			return 0;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && nx == sx && ny == sy)
		{
			cout << "Valid\n";
			return 0;
		}
	}

	cout << "Invalid\n";

	return 0;
}