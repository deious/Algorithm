#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

bool alpha[26];

string solution(string input_string) {
	string answer = "";
	int len = input_string.size();
	memset(alpha, true, sizeof(alpha));
	map<char, int> m;

	for (int i = 0; i < len; i++)
	{
		m[input_string[i] - 'a']++;
		alpha[input_string[i] - 'a'] = false;
	}

	for (int i = 0; i < 26; i++)
	{
		if (m[i] == 1)
		{
			alpha[i] = true;
		}
	}

	int amountCnt = 1;
	char temp = input_string[0];

	for (int i = 1; i < len; i++)
	{
		if (temp == input_string[i])
		{
			amountCnt++;
			if (amountCnt == m[temp - 'a'])
			{
				alpha[temp - 'a'] = true;
			}
		}
		else
		{
			amountCnt = 1;
			temp = input_string[i];
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (!alpha[i])
		{
			answer.push_back('a' + i);
		}
	}

	if (answer.size() == 0)
	{
		answer.push_back('N');
	}

	return answer;
}