#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	sort(rocks.begin(), rocks.end());
	int left = 0, right = distance, mid;
	int len = rocks.size();

	while (left <= right)
	{
		int cnt = 0;
		int prev = 0;
		mid = (left + right) / 2;

		for (int i = 0; i < len; i++)
		{
			if (rocks[i] - prev < mid)
				cnt++;
			else
				prev = rocks[i];
		}

		if (distance - prev < mid)
			cnt++;

		if (cnt <= n)
		{
			answer = mid > answer ? mid : answer;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	return answer;
}