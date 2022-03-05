#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool root[17][17];
int dp[17][(1 << 17) - 1];

int DFS(int start, int check, vector<int> &info)
{
	int &temp = dp[start][check];
	if (temp != -1)
		return temp;

	int sheep = 0, wolf = 0;
	for (int i = 0; i < 17; i++)
	{
		if (check & (1 << i))
		{
			if (info[i] == 1)
				wolf++;
			else
				sheep++;
		}
	}

	if (wolf >= sheep)
		return temp = 0;

	temp = sheep;
	for (int i = 0; i < 17; i++)
	{
		if (!root[start][i])
			continue;
		temp = max(temp, DFS(i, check | (1 << i), info));
	}

	return temp;
}

int solution(vector<int> info, vector<vector<int>> edges) {
	int answer = 0;
	for (auto au : edges)
		root[au[0]][au[1]] = root[au[1]][au[0]] = true;

	memset(dp, -1, sizeof(dp));
	answer = DFS(0, 1, info);

	return answer;
}