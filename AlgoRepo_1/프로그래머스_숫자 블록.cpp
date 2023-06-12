#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
	vector<int> answer;
	for (int i = begin; i <= end; i++)
	{
		if (i == 1)
		{
			answer.push_back(0);
			continue;
		}

		long long saveNum = 1;

		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0 && i / j <= 10000000)
			{
				saveNum = i / j;
				break;
			}
			else if (i % j == 0 && i / j > 10000000 && j <= 10000000 && j > saveNum)
			{
				saveNum = j;
			}
		}

		answer.push_back(saveNum);
	}

	return answer;
}