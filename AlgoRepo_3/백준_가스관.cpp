#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char board[25][25];
int R, C, dir = -1;

queue<pair<int, int>> q;

bool InRange(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < C;
}

void PipeCheck(int x, int y)
{
	bool dirArr[4] = { false, };

	int nx, ny;
	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (InRange(nx, ny) && board[nx][ny] != '.')
		{
			if (i == 0 && (board[nx][ny] == '|' || board[nx][ny] == '+'|| board[nx][ny] == '2' || board[nx][ny] == '3'))
				dirArr[i] = true;
			else if (i == 1 && (board[nx][ny] == '|' || board[nx][ny] == '+' || board[nx][ny] == '1' || board[nx][ny] == '4'))
				dirArr[i] = true;
			else if (i == 2 && (board[nx][ny] == '-' || board[nx][ny] == '+' || board[nx][ny] == '1' || board[nx][ny] == '2'))
				dirArr[i] = true;
			else if (i == 3 && (board[nx][ny] == '-' || board[nx][ny] == '+' || board[nx][ny] == '3' || board[nx][ny] == '4'))
				dirArr[i] = true;
		}
	}

	cout << x + 1 << " " << y + 1;
	if (dirArr[0] && dirArr[1] && dirArr[2] && dirArr[3])
		cout << " +\n";
	else if (dirArr[0] && dirArr[1])
		cout << " |\n";
	else if (dirArr[2] && dirArr[3])
		cout << " -\n";
	else if (dirArr[0] && dirArr[3])
		cout << " 1\n";
	else if (dirArr[1] && dirArr[3])
		cout << " 2\n";
	else if (dirArr[1] && dirArr[2])
		cout << " 3\n";
	else if (dirArr[0] && dirArr[2])
		cout << " 4\n";

	return;
}

void FindDir(int x, int y)
{
	int nx, ny;

	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (InRange(nx, ny) && board[nx][ny] != '.')
		{
			if (nx == x)
			{
				if (ny == y - 1)
					dir = 2;
				else if (ny == y + 1)
					dir = 3;
			}
			else
			{
				if (nx == x - 1)
					dir = 1;
				else if (ny == x + 1)
					dir = 0;
			}
		}
	}

	return;
}

void DFS(int x, int y, int z)
{
	if (board[x][y] == '.')
	{
		PipeCheck(x, y);
		return;
	}

	int nx = x + dx[z];
	int ny = y + dy[z];

	if (!InRange(nx, ny))
		return;

	if (z == 0)
	{
		if (board[nx][ny] == '|' && board[nx][ny] == '+')
			z = 0;
		else if (board[nx][ny] == '2')
			z = 3;
		else if (board[nx][ny] == '3')
			z = 2;
	}
	else if (z == 1)
	{
		if (board[nx][ny] == '|' && board[nx][ny] == '+')
			z = 1;
		else if (board[nx][ny] == '1')
			z = 3;
		else if (board[nx][ny] == '4')
			z = 2;
	}
	else if (z == 2)
	{
		if (board[nx][ny] == '-' && board[nx][ny] == '+')
			z = 2;
		else if (board[nx][ny] == '1')
			z = 0;
		else if (board[nx][ny] == '2')
			z = 1;
	}
	else
	{
		if (board[nx][ny] == '-' && board[nx][ny] == '+')
			z = 3;
		else if (board[nx][ny] == '3')
			z = 1;
		else if (board[nx][ny] == '4')
			z = 0;
	}

	DFS(nx, ny, z);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'M')
				q.push(make_pair(i, j));
			else if (board[i][j] == 'Z')
				q.push(make_pair(i, j));
		}
	}

	int x, y;
	while (dir == -1)
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		FindDir(x, y);

		if (dir != -1)
			DFS(x, y, dir);
	}

	return 0;
}