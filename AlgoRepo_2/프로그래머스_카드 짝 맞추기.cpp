#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

vector<vector<int>> tBoard;
bool check[7];

int tr, tc;

bool InRange(int x, int y)
{
	return x >= 0 && x < 4 && y >= 0 && y < 4;
}

int BFS(int n, int r, int c)
{
	bool checkBoard[4][4];
	memset(checkBoard, false, sizeof(checkBoard));
	queue<tuple<int, int, int>> q;
	q.push({ r, c, 0 });
	checkBoard[r][c] = true;

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int move = get<2>(q.front());
		q.pop();

		if (tBoard[x][y] == n)
		{
			tBoard[x][y] = 0;
			tr = x, tc = y;
			return move + 1;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny))
			{
				if (!checkBoard[nx][ny])
				{
					q.push({ nx, ny, move + 1 });
					checkBoard[nx][ny] = true;
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x;
			int ny = y;

			while (nx + dx[i] >= 0 && nx + dx[i] < 4 && ny + dy[i] >= 0 && ny + dy[i] < 4)
			{
				nx += dx[i];
				ny += dy[i];

				if (tBoard[nx][ny])
					break;
			}

			if (!checkBoard[nx][ny])
			{
				q.push({ nx, ny, move + 1 });
				checkBoard[nx][ny] = true;
			}
		}
	}
}

int solution(vector<vector<int>> board, int r, int c) {
	int answer = 2100000000;
	vector<int> v;

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j])
				check[board[i][j]] = true;
		}
	}

	for (int i = 1; i < 7; i++)
		if (check[i])
			v.push_back(i);

	do
	{
		tBoard = board;
		int temp = 0;
		tr = r, tc = c;

		for (int i = 0; i < v.size(); i++)
		{
			temp += BFS(v[i], tr, tc);
			temp += BFS(v[i], tr, tc);
		}

		answer = min(temp, answer);
	} while (next_permutation(v.begin(), v.end()));

	return answer;
}