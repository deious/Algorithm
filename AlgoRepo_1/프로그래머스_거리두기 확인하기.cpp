#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool check[5][5];

bool InRange(int x, int y)
{
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	int row = places.size();
	int col = places[0].size();

	bool breakCheck = false;

	for (int i = 0; i < 5; i++)
	{
		breakCheck = false;
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < col; k++)
			{
				if (places[i][j][k] == 'P')
				{
					memset(check, false, sizeof(check));
					queue<tuple<int, int, int>> q;
					q.push(make_tuple(j, k, 0));
					check[j][k] = true;

					while (!q.empty())
					{
						int x = get<0>(q.front());
						int y = get<1>(q.front());
						int dist = get<2>(q.front());
						q.pop();

						if (dist == 2)
							continue;

						for (int l = 0; l < 4; l++)
						{
							int nx = x + dx[l];
							int ny = y + dy[l];

							if (InRange(nx, ny) && places[i][nx][ny] == 'P' && !check[nx][ny])
							{
								breakCheck = true;
								answer.push_back(0);
								break;
							}
							else if (InRange(nx, ny) && places[i][nx][ny] == 'O' && !check[nx][ny])
							{
								check[nx][ny] = true;
								q.push(make_tuple(nx, ny, dist + 1));
							}
						}
						if (breakCheck)
							break;
					}
				}
				if (breakCheck)
					break;
			}
			if (breakCheck)
				break;
		}
		if (!breakCheck)
			answer.push_back(1);
	}

	return answer;
}