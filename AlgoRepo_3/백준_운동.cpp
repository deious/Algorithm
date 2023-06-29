#include <iostream>

using namespace std;

long long graph[401][401];
int V, E;

void floyd()
{
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (int k = 1; k <= V; k++)
			{
				if (graph[j][i] + graph[i][k] < graph[j][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			graph[i][j] = 2100000000;

	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	int ans = 2100000000;

	floyd();

	for (int i = 1; i <= V; i++)
	{
		if (graph[i][i] < ans)
			ans = graph[i][i];
	}

	if (ans == 2100000000)
		cout << "-1\n";
	else
		cout << ans << "\n";

	return 0;
}