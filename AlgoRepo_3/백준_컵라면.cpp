#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;

	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}
	
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		if (pq.empty())
			pq.push(v[i].second);
		else if (pq.size() < v[i].first)
			pq.push(v[i].second);
		else
		{
			if (pq.top() < v[i].second)
			{
				pq.pop();
				pq.push(v[i].second);
			}
		}
	}

	int answer = 0;
	while (!pq.empty())
	{
		answer += pq.top();
		pq.pop();
	}

	cout << answer << "\n";

	return 0;
}