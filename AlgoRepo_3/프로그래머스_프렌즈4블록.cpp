#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool check[30][30];

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int row = board.size();
	int col = board[0].size();

	bool endCheck = false;
	while (1)
	{
		memset(check, false, sizeof(check));
		endCheck = false;

		for (int i = 0; i < row - 1; i++)
		{
			for (int j = 0; j < col - 1; j++)
			{
				char c = board[i][j];
				if (c == ' ')
					continue;
				if (c == board[i + 1][j] && c == board[i + 1][j + 1] && c == board[i][j + 1])
				{
					check[i][j] = true;
					check[i + 1][j] = true;
					check[i][j + 1] = true;
					check[i + 1][j + 1] = true;
					endCheck = true;
				}
			}
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (check[i][j])
				{
					answer++;
					for (int k = i; k > 0; k--)
					{
						board[k][j] = board[k - 1][j];
						board[k - 1][j] = ' ';
					}
				}
			}
		}

		if (!endCheck)
			break;
	}
	return answer;
}