#include <iostream>
#include <vector>

using namespace std;

int num[100001];
bool check[100001];
vector<int> graph[100001];

int N, R, Q;

int DFS(int x)
{
	if (num[x])
		return num[x];

	check[x] = true;
	
	int ans = 1;
	int len = graph[x].size();

	for (int i = 0; i < len; i++)
	{
		int next = graph[x][i];
		if (check[next])
			continue;

		ans += DFS(next);
	}

	num[x] = ans;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> R >> Q;

	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	num[R] = DFS(R);

	for (int i = 0; i < Q; i++)
	{
		cin >> u;
		cout << num[u] << "\n";
	}

	return 0;
}