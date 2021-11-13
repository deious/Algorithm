#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int board[101][101];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
	int ldx, ldy, rux, ruy;
	int len = rectangle.size();

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 4; j++)
			rectangle[i][j] *= 2;

		ldx = rectangle[i][0], ldy = rectangle[i][1];
		rux = rectangle[i][2], ruy = rectangle[i][3];

		for (int j = ldy; j <= ruy; j++)
			for (int k = ldx; k <= rux; k++)
				board[j][k] = 1;
	}

	for (int i = 0; i < len; i++)
	{
		ldx = rectangle[i][0], ldy = rectangle[i][1];
		rux = rectangle[i][2], ruy = rectangle[i][3];

		for (int j = ldy + 1; j < ruy; j++)
			for (int k = ldx + 1; k < rux; k++)
				board[j][k] = 0;
	}

	queue<pair<int, int>> q;
	q.push({ characterY, characterX });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == itemY && x == itemX)
			break;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (board[ny][nx] == 1)
			{
				q.push({ ny, nx });
				board[ny][nx] = board[y][x] + 1;
			}
		}
	}

	return board[itemY][itemX] / 2;
}