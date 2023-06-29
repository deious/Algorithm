#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

bool check[101][101];

int solution(vector<vector<int> > maps)
{
	int answer = -1;
	int row = maps.size();
	int col = maps[0].size();

	memset(check, false, sizeof(check));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 1));

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int moveCount = get<2>(q.front());
		q.pop();

		if (x == row - 1 && y == col - 1)
		{
			answer = moveCount;
			return answer;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < row && ny >= 0 && ny < col && !check[nx][ny] && maps[nx][ny])
			{
				check[nx][ny] = true;
				q.push(make_tuple(nx, ny, moveCount + 1));
			}
		}
	}

	return answer;
}