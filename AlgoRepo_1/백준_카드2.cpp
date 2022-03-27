#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	queue<int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);

	while (!q.empty())
	{
		if (q.size() == 1)
		{
			cout << q.front() << "\n";
			return 0;
		}

		q.pop();
		int x = q.front();
		q.pop();
		q.push(x);
	}

	return 0;
}