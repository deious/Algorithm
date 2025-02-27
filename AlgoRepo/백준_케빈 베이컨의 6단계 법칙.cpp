#include <iostream>

using namespace std;

int graph[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int a, b;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			graph[i][j] = 100000;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (graph[i][k] + graph[k][j] < graph[i][j])
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	int temp = 100000;
	int tAnswer = 0;
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		tAnswer = 0;
		for (int j = 1; j <= N; j++)
		{
			tAnswer += graph[i][j];
		}

		if (tAnswer < temp)
		{
			temp = tAnswer;
			answer = i;
		}
	}

	cout << answer << "\n";

	return 0;
}