#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	int L, P, index = 0, answer = 0;
	cin >> L >> P;
	priority_queue<int, vector<int>, less<int>> pq;
	while (P < L)
	{
		while (index < N && v[index].first <= P)
			pq.push(v[index++].second);

		if (!pq.empty())
		{
			P += pq.top();
			pq.pop();
			answer++;
		}
		else
		{
			answer = -1;
			break;
		}
	}

	cout << answer << "\n";

	return 0;
}