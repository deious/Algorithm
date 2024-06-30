#include <iostream>

using namespace std;

int graph[1001];
bool check[1001];

void DFS(int num)
{
	check[num] = true;

	if (!check[graph[num]])
	{
		DFS(graph[num]);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N;
	cin >> T;

	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			check[i] = false;
			cin >> graph[i];
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			if (!check[i])
			{
				DFS(i);
				cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}