#include <iostream>
#include <queue>

using namespace std;

bool check[2][500001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;

	cin >> N >> K;
	if (N == K) 
	{
		cout << "0";
		return 0;
	}

	queue<int> q;
	q.push(N);
	int time = 1;
	check[0][N] = true;

	while (!q.empty()) 
	{
		K += time;

		if (K > 500000)
		{
			cout << -1 << "\n";
			return 0;
		}
		if (check[time % 2][K])
		{
			cout << time << "\n";
			return 0;
		}

		int len = q.size();
		for (int i = 0; i < len; i++) 
		{
			int x = q.front();
			q.pop();

			for (int nx : {x - 1, x + 1, 2 * x}) 
			{
				if (nx == K) 
				{
					cout << time << "\n";
					return 0;
				}

				if (nx < 0 || nx > 500000) 
					continue;
				if (check[time % 2][nx])
					continue;
				check[time % 2][nx] = true;
				q.push(nx);
			}
		}
		time++;
	}
	
	return 0;
}