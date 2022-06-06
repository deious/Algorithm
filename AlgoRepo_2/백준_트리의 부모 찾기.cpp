#include <iostream>
#include <vector>

using namespace std;

int node[100001];
vector<int> graph[100001];

void DFS(int num, int nodeNum)
{
	node[num] = nodeNum;

	for (int i = 0; i < graph[num].size(); i++)
	{
		if (node[graph[num][i]] == 0)
			DFS(graph[num][i], num);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1, 1);
	for (int i = 2; i <= N; i++)
		cout << node[i] << "\n";

	return 0;
}