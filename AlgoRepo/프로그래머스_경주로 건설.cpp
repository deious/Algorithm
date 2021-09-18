#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int dist[25][25];

struct info {
	int x, y, dir, distance;
};

int solution(vector<vector<int>> board) {
	int answer = 0;
	int row = board.size();
	int col = board[0].size();

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			dist[i][j] = 210000000;

	dist[0][0] = -1;

	queue<info> q;
	info inf;
	inf.x = 0, inf.y = 0, inf.dir = 0, inf.distance = 0;
	q.push(inf);

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int dis = q.front().distance;
		q.pop();

		if (x == row - 1 && y == col - 1)
			continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nDis = dis;

			if (nx >= 0 && nx < row && ny >= 0 && ny < col && !board[nx][ny])
			{
				nDis += 100;
				if (dir != i)
					nDis += 500;

				if (dist[nx][ny] >= nDis)
				{
					dist[nx][ny] = nDis;
					inf.x = nx, inf.y = ny, inf.dir = i, inf.distance = nDis;
					q.push(inf);
				}
			}
		}
	}

	inf.x = 0, inf.y = 0, inf.dir = 1, inf.distance = 0;
	q.push(inf);

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int dis = q.front().distance;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nDis = dis;

			if (nx >= 0 && nx < row && ny >= 0 && ny < col && !board[nx][ny])
			{
				nDis += 100;
				if (dir != i)
					nDis += 500;

				if (dist[nx][ny] >= nDis)
				{
					dist[nx][ny] = nDis;
					inf.x = nx, inf.y = ny, inf.dir = i, inf.distance = nDis;
					q.push(inf);
				}
			}
		}
	}

	answer = dist[row - 1][col - 1];
	return answer;
}