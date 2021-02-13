#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int maxCount = 0;
	int len = edge.size();
	queue<int> q;
	vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
	vector<bool> check(n + 1, false);
	vector<int> distance(n + 1, 0);

	for (int i = 0; i < len; i++)
	{
		graph[edge[i][0]][edge[i][1]] = true;
		graph[edge[i][1]][edge[i][0]] = true;
	}

	q.push(1);
	check[1] = true;
	distance[1] = 0;

	sort(edge.begin(), edge.end());

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int i = 2; i <= n; i++)
		{
			if (graph[x][i] && !check[i])
			{
				distance[i] = distance[x] + 1;
				check[i] = true;
				q.push(i);

				if (distance[i] > maxCount) maxCount = distance[i];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (distance[i] == maxCount) answer++;
	}

	return answer;
}