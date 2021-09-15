#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer(2);
	set<string> s;
	int len = gems.size();
	for (int i = 0; i < len; i++)
		s.insert(gems[i]);

	map<string, int> m;
	int start = 0, end = 0, mLen;

	for (auto str : gems)
	{
		m[str]++;
		if (m.size() == s.size())
			break;
		end++;
	}

	mLen = end - start;

	answer[0] = start + 1;
	answer[1] = end + 1;

	while (end < len)
	{
		string str = gems[start];
		m[str]--;
		start++;

		if (!m[str])
		{
			end++;
			for (; end < len; end++)
			{
				m[gems[end]]++;
				if (str == gems[end])
					break;
			}

			if (end == len)
				break;
		}

		if (end - start < mLen)
		{
			answer[0] = start + 1;
			answer[1] = end + 1;
			mLen = end - start;
		}

	}

	return answer;
}