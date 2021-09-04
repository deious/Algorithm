#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	sort(jobs.begin(), jobs.end());

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int index = 0, time = 0, len = jobs.size();

	while (index < len || !pq.empty())
	{
		if (index < len && time >= jobs[index][0])
		{
			pq.push(make_pair(jobs[index][1], jobs[index][0]));
			index++;
			continue;
		}

		if (!pq.empty())
		{
			time += pq.top().first;
			answer += time - pq.top().second;
			pq.pop();
		}
		else
			time = jobs[index][0];
	}

	return answer / len;
}