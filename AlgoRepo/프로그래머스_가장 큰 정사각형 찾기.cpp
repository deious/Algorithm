#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
	int ans = 0;
	int w = board[0].size();
	int h = board.size();

	if (w == 1 && h == 1)
	{
		if (board[0][0] == 1) return 1;
		else return 0;
	}

	for (int i = 1; i < h; i++)
	{
		for (int j = 1; j < w; j++)
		{
			if (board[i][j])
			{
				board[i][j] = min({ board[i - 1][j], board[i][j - 1], board[i - 1][j - 1] }) + 1;
				ans = max(ans, board[i][j]);
			}
		}
	}

	return ans * ans;
}