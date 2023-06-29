#include <string>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<int> answer(2);

void checkValue(int x, int y, int size, int standard)
{
	bool check = false;

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (board[i][j] != standard)
			{
				check = true;
				break;
			}
		}
		if (check) break;
	}

	if (!check)
	{
		answer[standard]++;
		return;
	}

	size /= 2;

	checkValue(x, y, size, board[x][y]);
	checkValue(x, y + size, size, board[x][y + size]);
	checkValue(x + size, y, size, board[x + size][y]);
	checkValue(x + size, y + size, size, board[x + size][y + size]);
}

vector<int> solution(vector<vector<int>> arr)
{
	board = arr;
	checkValue(0, 0, arr.size(), arr[0][0]);
	return answer;
}