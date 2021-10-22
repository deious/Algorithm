#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
	long long answer = 10e14;
	long long start = 0, end = 10e14;

	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long gold = 0;
		long long silver = 0;
		long long sum = 0;

		int len = s.size();
		for (int i = 0; i < len; i++)
		{
			long long cGold = (long long)g[i];
			long long cSilver = (long long)s[i];
			long long cW = (long long)w[i];
			long long cT = (long long)t[i];
			long long moveCount = mid / (cT * 2);
			if (mid % (cT * 2) >= t[i])
				moveCount++;

			gold += (cGold < moveCount * cW) ? cGold : moveCount * cW;
			silver += (cSilver < moveCount * cW) ? cSilver : moveCount * cW;
			sum += (cGold + cSilver < moveCount * cW) ? cGold + cSilver : moveCount * cW;
		}

		if (gold >= a && silver >= b && sum >= a + b)
		{
			end = mid - 1;
			answer = min(answer, mid);
		}
		else
			start = mid + 1;
	}

	return answer;
}