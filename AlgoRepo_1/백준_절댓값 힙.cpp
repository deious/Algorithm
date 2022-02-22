#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == 0)
		{
			if (pq.size() == 0)
				cout << "0\n";
			else
			{
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else
		{
			if (a < 0)
				pq.push({ -a, a });
			else
				pq.push({ a, a });
		}
	}

	return 0;
}