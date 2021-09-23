#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	int answer = 0;
	int len = edge_list.size();

	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < len; i++)
	{
		graph[edge_list[i][0]].push_back(edge_list[i][1]);
		graph[edge_list[i][1]].push_back(edge_list[i][0]);
	}

	vector<vector<int>> dp(k, vector<int>(n + 1, 2100000000));
	dp[0][gps_log[0]] = 0;

	for (int i = 1; i < k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int minCount = dp[i - 1][j];

			for (int k = 0; k < graph[j].size(); k++)
				minCount = min(minCount, dp[i - 1][graph[j][k]]);

			if (gps_log[i] != j)
				dp[i][j] = minCount + 1;
			else
				dp[i][j] = minCount;
		}
	}

	answer = dp[k - 1][gps_log[k - 1]];

	if (answer >= 2100000000)
		answer = -1;

	return answer;
}