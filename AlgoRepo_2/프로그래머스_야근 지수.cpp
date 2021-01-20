#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
	long long answer = 0;
	priority_queue<int> pq;

	int len = works.size();

	for (int i = 0; i < len; i++) pq.push(works[i]);

	for (int i = 0; i < n; i++)
	{
		int temp = pq.top();
		pq.pop();
		temp--;
		if (temp > 0) pq.push(temp);
	}

	int len2 = pq.size();

	for (int i = 0; i < len2; i++)
	{
		int temp = pq.top();
		pq.pop();
		answer += temp * temp;
	}

	return answer;
}