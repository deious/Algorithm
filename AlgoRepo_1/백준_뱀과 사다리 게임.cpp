#include <iostream>
#include <queue>

using namespace std;

int save[101];
int ladderSnake[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	queue<int> q;

	int a, N, M, len;
	cin >> N >> M;
	len = N + M;

	for (int i = 0; i < len; i++)
	{
		cin >> a;
		cin >> ladderSnake[a];
	}

	q.push(1);

	while (!q.empty())
	{
		int x = q.front();
		if (x == 100)
			break;
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int nx = x + i;
			if (nx > 100)
				continue;

			if (ladderSnake[nx] != 0)
			{
				nx = ladderSnake[nx];
			}

			if (save[nx] == 0)
			{
				save[nx] = save[x] + 1;
				q.push(nx);
			}
		}
	}

	cout << save[100] << "\n";

	return 0;
}