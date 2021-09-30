#include <string>

using namespace std;

bool board[11][11][11][11];

bool InRange(int x, int y)
{
	return x >= 0 && x < 11 && y >= 0 && y < 11;
}

int solution(string dirs) {
	int answer = 0;
	int len = dirs.size();

	int x = 5, y = 5;
	int nx = 0, ny = 0;

	char c;
	for (int i = 0; i < len; i++)
	{
		c = dirs[i];
		nx = x, ny = y;

		if (c == 'U')
			nx--;
		else if (c == 'D')
			nx++;
		else if (c == 'R')
			ny++;
		else
			ny--;

		if (InRange(nx, ny))
		{
			if (!board[x][y][nx][ny])
			{
				board[x][y][nx][ny] = true;
				board[nx][ny][x][y] = true;
				answer++;
			}

			x = nx;
			y = ny;
		}
	}

	return answer;
}