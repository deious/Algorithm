#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

vector<string> v;
int row, col;
string answer = "";

bool InRange(int x, int y)
{
	return x >= 0 && x < row && y >= 0 && y < col;
}

bool AlphaCheck(int x, int y)
{
	char c = v[x][y];
	queue<tuple<int, int, int, int>> q;
	q.push({ x, y, -1, 0 });

	while (!q.empty())
	{
		int tx = get<0>(q.front());
		int ty = get<1>(q.front());
		int dir = get<2>(q.front());
		int curveCount = get<3>(q.front());
		char tc = v[tx][ty];
		q.pop();

		if (curveCount > 1)
			continue;

		if (c == tc && (x != tx || y != ty))
		{
			answer.push_back(c);
			v[x][y] = '.';
			v[tx][ty] = '.';
			return true;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (InRange(nx, ny) && (v[nx][ny] == '.' || v[nx][ny] == c))
			{
				if (dir == -1)
					q.push({ nx, ny, i, curveCount });
				else if (dir == i)
					q.push({ nx, ny, i, curveCount });
				else if (dir != i)
					q.push({ nx, ny, i, curveCount + 1 });
			}
		}
	}

	return false;
}

string solution(int m, int n, vector<string> board) {
	v = board;
	row = board.size();
	col = board[0].size();
	answer = "";
	vector<pair<char, pair<int, int>>> v1;
	map<char, int> alphaSave;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] >= 'A' && board[i][i] <= 'Z' && alphaSave[board[i][j]] == 0)
			{
				alphaSave[board[i][j]]++;
				v1.push_back({ board[i][j],{ i, j } });
			}
		}
	}
	sort(v1.begin(), v1.end());

	bool endCheck = false;
	while (!endCheck)
	{
		endCheck = true;
		for (int i = 0; i < v1.size(); i++)
		{
			if (AlphaCheck(v1[i].second.first, v1[i].second.second))
			{
				endCheck = false;
				v1.erase(v1.begin() + i);
				break;
			}
		}
		if (endCheck)
			break;
	}

	if (v1.empty())
		return answer;
	else
		return "IMPOSSIBLE";
}