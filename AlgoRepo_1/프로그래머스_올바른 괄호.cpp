#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
	stack<char> st;

	if (s[0] == ')') return false;

	for (int i = 0; i < s.size(); i++)
	{
		if (st.empty() && s[i] == '(') st.push(s[i]);
		else if (st.empty() && s[i] == ')') return false;
		else
		{
			if (st.top() != s[i]) st.pop();
			else st.push(s[i]);
		}
	}

	if (st.empty()) return true;
	else return false;
}