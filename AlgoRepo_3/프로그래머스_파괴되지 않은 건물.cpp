#include <string>
#include <vector>

using namespace std;

int checkBoard[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	int n = board.size();
	int m = board[0].size();

	for (auto au : skill)
	{
		int type = au[0], r1 = au[1], c1 = au[2], r2 = au[3], c2 = au[4], degree = au[5];

		if (type == 1)
			degree = -degree;
		checkBoard[r1][c1] += degree;
		checkBoard[r1][c2 + 1] -= degree;
		checkBoard[r2 + 1][c1] -= degree;
		checkBoard[r2 + 1][c2 + 1] += degree;
	}

	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++)
			checkBoard[i][j] += checkBoard[i - 1][j];

	for (int i = 0; i < n; i++)
		for (int j = 1; j < m; j++)
			checkBoard[i][j] += checkBoard[i][j - 1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (checkBoard[i][j] + board[i][j] > 0)
				answer++;

	return answer;
}