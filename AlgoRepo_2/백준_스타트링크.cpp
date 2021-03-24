#include <iostream>
#include <queue>

using namespace std;

bool check[1000001];

int F, S, G, U, D;

bool InRange(int x)
{
	return x > 0 && x <= F;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> F >> S >> G >> U >> D;

	queue<pair<int, int>> q;
	q.push(make_pair(S, 0));

	check[0] = true;
	check[S] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int count = q.front().second;

		if (x == G)
		{
			cout << count << "\n";
			return 0;
		}
		q.pop();

		for (int i = 0; i < 2; i++)
		{
			int nx = 0;
			if (i == 0)
				nx = x + U;
			else
				nx = x - D;

			if (InRange(nx) && !check[nx])
			{
				check[nx] = true;
				q.push(make_pair(nx, count + 1));
			}
		}
	}

	cout << "use the stairs\n";

	return 0;
}