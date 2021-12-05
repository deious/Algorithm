#include <vector>

using namespace std;

int N;
vector<vector<int>> Board;

bool CheckFill(int row, int col)
{
	for (int i = 0; i < row; i++)
		if (Board[i][col] != 0)
			return false;

	return true;
}

bool Find(int row, int col, int h, int w)
{
	int emptyCnt = 0;
	int lastValue = -1;
	for (int i = row; i < row + h; i++)
	{
		for (int j = col; j < col + w; j++)
		{
			if (Board[i][j] == 0)
			{
				if (!CheckFill(i, j))
					return false;
				if (++emptyCnt > 2)
					return false;
			}
			else
			{
				if (lastValue != -1 && lastValue != Board[i][j])
					return false;
				lastValue = Board[i][j];
			}
		}
	}

	for (int i = row; i < row + h; i++)
		for (int j = col; j < col + w; j++)
			Board[i][j] = 0;

	return true;
}

int solution(vector<vector<int>> board) {
	Board = board;
	N = board.size();
	int answer = 0, cnt;
	do
	{
		cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i <= N - 3 && j <= N - 2 && Find(i, j, 3, 2))
					cnt++;
				else if (i <= N - 2 && j <= N - 3 && Find(i, j, 2, 3))
					cnt++;
			}
		}
		answer += cnt;
	} while (cnt);

	return answer;
}