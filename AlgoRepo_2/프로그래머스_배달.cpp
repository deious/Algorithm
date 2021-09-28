#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;
	vector<pair<int, int>> v[51];
	vector<int> distance(51, 2100000000);
	priority_queue<int> pq;

	int len = road.size();
	int a, b, c;
	for (int i = 0; i < len; i++)
	{
		a = road[i][0];
		b = road[i][1];
		c = road[i][2];

		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	pq.push(1);
	distance[1] = 0;

	while (!pq.empty())
	{
		int pos = pq.top();
		pq.pop();

		for (int i = 0; i < v[pos].size(); i++)
		{
			int nPos = v[pos][i].first;
			int nCost = v[pos][i].second;

			if (distance[nPos] > distance[pos] + nCost)
			{
				distance[nPos] = distance[pos] + nCost;
				pq.push(nPos);
			}
		}
	}

	for (int i = 1; i <= N; i++)
		if (distance[i] <= K)
			answer++;

	return answer;
}