#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int> minQueue;
	priority_queue<int, vector<int>, greater<int>> maxQueue;

	int N, num;
	cin >> N;

	while (N--)
	{
		cin >> num;

		if (minQueue.empty())
			minQueue.push(num);
		else if (minQueue.size() == maxQueue.size())
			minQueue.push(num);
		else
			maxQueue.push(num);

		if (!minQueue.empty() && !maxQueue.empty() && minQueue.top() > maxQueue.top())
		{
			int a = minQueue.top();
			int b = maxQueue.top();

			minQueue.pop();
			maxQueue.pop();

			minQueue.push(b);
			maxQueue.push(a);
		}

		cout << minQueue.top() << "\n";
	}

	return 0;
}