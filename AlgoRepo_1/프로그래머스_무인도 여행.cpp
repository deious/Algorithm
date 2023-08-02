#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int lenX, lenY;
bool check[100][100];

bool InRange(int x, int y)
{
	return x >= 0 && x < lenX && y >= 0 && y < lenY;
}

vector<int> solution(vector<string> maps) {
	vector<int> answer;

	lenX = maps.size();
	lenY = maps[0].size();
	for (int i = 0; i < lenX; i++)
	{
		for (int j = 0; j < lenY; j++)
		{
			if (!check[i][j] && maps[i][j] != 'X')
			{
				int num = 0;
				queue<pair<int, int>> q;
				q.push({ i, j });

				while (!q.empty())
				{
					pair<int, int> p = q.front();
					q.pop();
					num += maps[p.first][p.second] - '0';
					check[p.first][p.second] = true;

					for (int k = 0; k < 4; k++)
					{
						int nx = p.first + dx[k];
						int ny = p.second + dy[k];

						if (!check[nx][ny] && InRange(nx, ny) && maps[nx][ny] != 'X')
						{
							check[nx][ny] = true;
							q.push({ nx, ny });
						}
					}
				}
				answer.push_back(num);
			}
		}
	}

	sort(answer.begin(), answer.end());

	if (answer.size() == 0)
	{
		answer.push_back(-1);
	}

	return answer;
}