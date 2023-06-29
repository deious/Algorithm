#include <string>
#include <vector>
#include <map>
#include <cctype>

using namespace std;

map<string, char> m;

int solution(string s) {
	string answer = "";
	m["zero"] = '0';
	m["one"] = '1';
	m["two"] = '2';
	m["three"] = '3';
	m["four"] = '4';
	m["five"] = '5';
	m["six"] = '6';
	m["seven"] = '7';
	m["eight"] = '8';
	m["nine"] = '9';

	int len = s.size();
	string temp = "";
	for (int i = 0; i < len; i++)
	{
		if (isdigit(s[i]) == 0)
		{
			temp.push_back(s[i]);
			if (m.find(temp) != m.end())
			{
				answer.push_back(m[temp]);
				temp = "";
			}
		}
		else
			answer.push_back(s[i]);
	}

	return stoi(answer);
}