#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	stack<char> st;

	cin >> str;
	int res = 0;

	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			st.push('(');
		}
		else
		{
			if (st.empty())
			{
				res++;
			}
			else
			{
				st.pop();
			}
		}
	}

	res += st.size();
	cout << res << "\n";

	return 0;
}