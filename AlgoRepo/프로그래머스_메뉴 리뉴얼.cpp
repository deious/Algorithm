#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int maxCount[11] = { 0, };
unordered_map<string, int> m[11];

void combination(string str, int pos, string st)
{
	if (pos >= str.size())
	{
		int len = st.size();
		if (len >= 2)
		{
			m[len][st]++;
			maxCount[len] = max(maxCount[len], m[len][st]);
		}

		return;
	}

	combination(str, pos + 1, st + str[pos]);
	combination(str, pos + 1, st);
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (auto au : orders)
	{
		sort(au.begin(), au.end());
		combination(au, 0, "");
	}

	for (int len : course)
		for (auto au : m[len])
			if (au.second >= 2 && au.second == maxCount[len])
				answer.push_back(au.first);

	sort(answer.begin(), answer.end());
	return answer;
}