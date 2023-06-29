#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
	stack<char> sc;

	for (int i = 0; i < s.size(); i++)
	{
		if (sc.size() > 0 && sc.top() == s[i]) sc.pop();
		else sc.push(s[i]);
	}

	if (sc.empty()) return 1;
	else return 0;
}