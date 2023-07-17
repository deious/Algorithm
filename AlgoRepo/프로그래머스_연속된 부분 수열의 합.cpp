#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	pair<int, int> answer;
	int start = 0, end = 0;
	int sum = sequence[0];
	int len = sequence.size();
	int tempLen = len;

	while (start <= end && end < len)
	{
		if (sum < k)
		{
			sum += sequence[++end];
		}
		else if (sum == k)
		{
			if (tempLen > end - start)
			{
				tempLen = end - start;
				answer = { start, end };
			}

			sum -= sequence[start++];
		}
		else
		{
			sum -= sequence[start++];
		}
	}

	return { answer.first, answer.second };
}