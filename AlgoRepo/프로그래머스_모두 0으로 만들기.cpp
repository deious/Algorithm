#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

long long answer = 0;

void DFS(int child, int parent, vector<long long> &sum, vector<vector<int>> &graph)
{
	int len = graph[child].size();
	for (int i = 0; i < len; i++)
	{
		if (graph[child][i] != parent)
			DFS(graph[child][i], child, sum, graph);
	}

	sum[parent] += sum[child];
	answer += abs(sum[child]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
	int len = a.size();
	int sumCheck = 0;
	for (int i = 0; i < len; i++)
		sumCheck += a[i];

	if (sumCheck != 0)
		return -1;

	vector<long long> sum(len);
	for (int i = 0; i < len; i++)
		sum[i] = a[i];

	vector<vector<int>> graph(len);
	int eLen = edges.size();
	for (int i = 0; i < eLen; i++)
	{
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}

	DFS(0, 0, sum, graph);

	if (sum[0] == 0)
		return answer;
	else
		return -1;
}