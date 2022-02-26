#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	int minLate = 0;
	int zero = 0;
	for (int i : lottos)
	{
		if (i == 0)
		{
			zero++;
			continue;
		}

		if (find(win_nums.begin(), win_nums.end(), i) != win_nums.end())
			minLate++;
	}

	if (minLate == 0 || minLate == 1)
	{
		if (minLate == 0 && zero == 0)
			answer.push_back(6);
		else
			answer.push_back(7 - minLate - zero);

		answer.push_back(6);
	}
	else
	{
		answer.push_back(7 - minLate - zero);
		answer.push_back(7 - minLate);
	}

	return answer;
}