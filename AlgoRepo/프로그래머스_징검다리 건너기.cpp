#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
	int answer = 0;
	int start = 1;
	int mid = 0;
	int end = *max_element(stones.begin(), stones.end());
	int len = stones.size();
	int count = 0;
	int temp = 0;

	while (start <= end)
	{
		mid = (start + end) / 2;
		count = 0;
		temp = 0;

		for (int i = 0; i < len; i++)
		{
			if (stones[i] < mid)
				count++;
			else
			{
				temp = max(temp, count);
				count = 0;
			}
		}

		temp = max(temp, count);

		if (temp >= k)
			end = mid - 1;
		else
		{
			answer = mid;
			start = mid + 1;
		}
	}

	return answer;
}