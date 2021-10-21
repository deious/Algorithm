#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int board[102][102];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
	vector<int> answer;
	int num = 1;
	for (int i = 1; i <= rows; i++)
		for (int j = 1; j <= columns; j++)
			board[i][j] = num++;

	int len = queries.size();
	for (int i = 0; i < len; i++)
	{
		int startX = queries[i][0];
		int startY = queries[i][1];
		int endX = queries[i][2];
		int endY = queries[i][3];

		int minNum = 210000000;
		int temp = board[startX][startY];
		int ttemp;
		for (int j = startY + 1; j <= endY; j++)
		{
			ttemp = board[startX][j];
			board[startX][j] = temp;
			minNum = min(minNum, temp);
			temp = ttemp;
		}
		minNum = min(minNum, temp);

		for (int j = startX + 1; j <= endX; j++)
		{
			ttemp = board[j][endY];
			minNum = min(minNum, ttemp);
			board[j][endY] = temp;
			temp = ttemp;
		}

		for (int j = endY - 1; j >= startY; j--)
		{
			ttemp = board[endX][j];
			minNum = min(minNum, ttemp);
			board[endX][j] = temp;
			temp = ttemp;
		}

		for (int j = endX - 1; j >= startX; j--)
		{
			ttemp = board[j][startY];
			minNum = min(minNum, ttemp);
			board[j][startY] = temp;
			temp = ttemp;
		}

		answer.push_back(minNum);
	}
	return answer;
}