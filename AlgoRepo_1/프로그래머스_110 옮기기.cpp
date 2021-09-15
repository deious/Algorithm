#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<string> solution(vector<string> s) {
	vector<string> answer(s.size());

	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		deque<char> dq;
		int count = 0;

		int sLen = s[i].size();
		for (int j = 0; j < sLen; j++)
		{
			dq.push_back(s[i][j]);
			int n = dq.size();
			if (n >= 3 && dq[n - 3] == '1' && dq[n - 2] == '1' && dq[n - 1] == '0')
			{
				count++;
				dq.pop_back();
				dq.pop_back();
				dq.pop_back();
			}
		}

		if (count == 0)
		{
			answer[i] = s[i];
			continue;
		}

		int idx = dq.size();
		string str = "";
		bool check = false;
		for (int i = dq.size() - 1; i >= 0; i--)
		{
			if (!check && dq[i] == '1')
				idx--;
			else
				check = true;

			str = dq[i] + str;
		}

		while (count--)
			str.insert(idx, "110");

		answer[i] = str;
	}

	return answer;
}