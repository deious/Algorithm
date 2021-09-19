#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer, state, uid;
	map<string, string> m;
	string s;

	int len = record.size();
	for (int i = 0; i < len; i++)
	{
		istringstream ss(record[i]);
		string str[3];
		int index = 0;

		while (getline(ss, s, ' '))
			str[index++] = s;

		if (str[0] == "Enter")
		{
			uid.push_back(str[1]);
			state.push_back("´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
			m[str[1]] = str[2];
		}
		else if (str[0] == "Leave")
		{
			uid.push_back(str[1]);
			state.push_back("´ÔÀÌ ³ª°¬½À´Ï´Ù.");
		}
		else if (str[0] == "Change")
			m[str[1]] = str[2];
	}

	int uLen = uid.size();

	for (int i = 0; i < uLen; i++)
	{
		s = m[uid[i]] + state[i];
		answer.push_back(s);
	}

	return answer;
}