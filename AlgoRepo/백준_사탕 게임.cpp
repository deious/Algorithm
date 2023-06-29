#include <cstdio>
#include <algorithm>

using namespace std;

char board[51][51];

int boardSize = 0;
int maxNum = 0;

void checkRow(int n)
{
	char temp = board[1][n];
	int saveNum = 0;
	int num = 1;

	for (int i = 2; i <= boardSize; i++)
	{
		if (temp == board[i][n])
			num++;
		else
		{
			temp = board[i][n];
			if (num > saveNum)
				saveNum = num;
			num = 1;
		}
	}

	maxNum = max({ maxNum, saveNum, num });
}

void checkCol(int n)
{
	char temp = board[n][1];
	int saveNum = 0;
	int num = 1;

	for (int i = 2; i <= boardSize; i++)
	{
		if (temp == board[n][i])
			num++;
		else
		{
			temp = board[n][i];
			if (num > saveNum)
				saveNum = num;
			num = 1;
		}
	}

	maxNum = max({ maxNum, saveNum, num });
}

int main()
{
	scanf("%d", &boardSize);

	for (int i = 1; i <= boardSize; i++)
		for (int j = 1; j <= boardSize; j++)
			scanf(" %1c", &board[i][j]);

	for(int i = 1; i <= boardSize; i++)
		for (int j = 1; j <= boardSize; j++)
		{
			if (i != boardSize && j != boardSize)
			{
				swap(board[i][j], board[i][j + 1]);
				checkCol(i);
				checkRow(j);
				checkRow(j + 1);
				swap(board[i][j], board[i][j + 1]);
				swap(board[i][j], board[i + 1][j]);
				checkCol(i);
				checkCol(i + 1);
				checkRow(j);
				swap(board[i][j], board[i + 1][j]);
			}
			else if (i == boardSize && j != boardSize)
			{
				swap(board[i][j], board[i][j + 1]);
				checkRow(i);
				checkCol(j);
				checkCol(j + 1);
				swap(board[i][j], board[i][j + 1]);
			}
			else if (i != boardSize && j == boardSize)
			{
				swap(board[i][j], board[i + 1][j]);
				checkCol(i);
				checkCol(i + 1);
				checkRow(j);
				swap(board[i][j], board[i + 1][j]);
			}
		}

	printf("%d\n", maxNum);

	return 0;
}