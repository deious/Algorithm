#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool check[501][501][4];

int CycleLength(int x, int y, int z, vector<string> grid)
{
	int len = 0;
	int row = grid.size();
	int col = grid[0].size();
	while (true)
	{
		if (check[x][y][z])
			break;

		len++;
		check[x][y][z] = true;
		if (grid[x][y] == 'L')
		{
			z--;
			if (z < 0)
				z = 3;
		}
		else if (grid[x][y] == 'R')
		{
			z++;
			if (z > 3)
				z = 0;
		}

		x += dx[z];
		y += dy[z];

		if (x < 0)
			x = row - 1;
		if (y < 0)
			y = col - 1;

		x %= row;
		y %= col;
	}

	return len;
}

vector<int> solution(vector<string> grid) {
	vector<int> answer;
	int row = grid.size();
	int col = grid[0].size();

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (check[i][j][k])
					continue;
				else
					answer.push_back(CycleLength(i, j, k, grid));
			}
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}