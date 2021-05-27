#include <iostream>

using namespace std;

int graph[10001];
bool check[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N, a, b, c, d;
	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			check[i] = false;
			graph[i] = i;
		}

		for (int i = 0; i < N - 1; i++)
		{
			cin >> a >> b;
			graph[b] = a;
		}

		cin >> c >> d;
		check[c] = true;

		while (c != graph[c])
		{
			c = graph[c];
			check[c] = true;
		}

		while (true)
		{
			if (check[d])
			{
				cout << d << "\n";
				break;
			}

			d = graph[d];
		}
	}

	return 0;
}