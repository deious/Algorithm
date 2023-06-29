#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer(2);

	while (s != "1")
	{
		answer[0]++;
		string tempString = "";

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '1') tempString += '1';
			else answer[1]++;
		}

		int len = tempString.size();
		s = "";

		while (len > 0)
		{
			s += to_string(len % 2);
			len /= 2;
		}
	}

	return answer;
}