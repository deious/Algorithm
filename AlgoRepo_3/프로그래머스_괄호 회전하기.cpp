#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
	int answer = 0;
	int len = s.size();
	if (len % 2 == 1)
		return 0;

	int total = len;
	while (total--)
	{
		stack<char> st;
		bool check = false;
		string temp = s.substr(total, len - total) + s.substr(0, total);

		for (int i = len - 1; i >= 0; i--)
		{
			if (st.empty())
			{
				if (temp[i] == ')' || temp[i] == ']' || temp[i] == '}')
					st.push(temp[i]);
				else
				{
					check = true;
					break;
				}
			}
			else
			{
				if (temp[i] == '(')
				{
					if (st.top() == ')')
						st.pop();
					else
						st.push(temp[i]);
				}
				else if (temp[i] == '[')
				{
					if (st.top() == ']')
						st.pop();
					else
						st.push(temp[i]);
				}
				else if (temp[i] == '{')
				{
					if (st.top() == '}')
						st.pop();
					else
						st.push(temp[i]);
				}
				else
					st.push(temp[i]);
			}
		}

		if (st.empty() && !check)
			answer++;
	}
	return answer;
}