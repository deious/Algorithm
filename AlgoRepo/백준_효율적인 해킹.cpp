#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> graph[10001];
bool check[10001];

int hackingCount = 0;
int maxCount = 0;

void DFS(int num)
{
	for (int i = 0; i < graph[num].size(); i++)
	{
		int x = graph[num][i];
		if (!check[x])
		{
			hackingCount++;
			check[x] = true;
			DFS(x);
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;


	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[b].push_back(a);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++)
	{
		hackingCount = 0;
		memset(check, false, sizeof(check));
		check[i] = true;
		DFS(i);

		if (hackingCount == maxCount)
			pq.push(i);
		else if (hackingCount > maxCount)
		{
			while (!pq.empty())
				pq.pop();

			pq.push(i);
			maxCount = hackingCount;
		}
	}

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	
	return 0;
}