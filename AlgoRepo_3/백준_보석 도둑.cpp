#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> zem[300000];
int bag[300000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> zem[i].first >> zem[i].second;

	for (int i = 0; i < K; i++)
		cin >> bag[i];

	sort(zem, zem + N);
	sort(bag, bag + K);


	long long answer = 0;
	int index = 0;
	priority_queue<int> pq;

	for (int i = 0; i < K; i++)
	{
		while (index < N && zem[index].first <= bag[i])
			pq.push(zem[index++].second);

		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer << "\n";

	return 0;
}