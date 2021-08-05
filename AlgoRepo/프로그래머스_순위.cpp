#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> leagueTable(n + 1, vector<bool>(n + 1, false));

	int len = results.size();

	for (int i = 0; i < len; i++)
		leagueTable[results[i][0]][results[i][1]] = true;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (leagueTable[j][i] && leagueTable[i][k])
					leagueTable[j][k] = true;
			}
		}
	}

	int winCount = 0;
	for (int i = 1; i <= n; i++)
	{
		winCount = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			if (leagueTable[i][j] || leagueTable[j][i])
				winCount++;
		}

		if (winCount == n - 1)
			answer++;
	}

	return answer;
}