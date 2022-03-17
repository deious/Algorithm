#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, x;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	while (N--)
	{
		cin >> x;
		if (x > 0)
			pq.push(x);
		else
		{
			if (pq.size() == 0)
				cout << "0\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}

	return 0;
}