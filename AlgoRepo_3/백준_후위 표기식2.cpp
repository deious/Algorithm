#include <iostream>
#include <stack>
#include <string>

using namespace std;

int num[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string postfix;
	cin >> N >> postfix;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	int len = postfix.size();
	stack<double> s;
	double front, back;
	for (int i = 0; i < len; i++)
	{
		if (postfix[i] >= 'A' && postfix[i] <= 'Z')
			s.push(num[postfix[i] - 'A']);
		else
		{
			if (postfix[i] == '+')
			{
				back = s.top();
				s.pop();
				front = s.top();
				s.pop();
				s.push(front + back);
			}
			else if (postfix[i] == '-')
			{
				back = s.top();
				s.pop();
				front = s.top();
				s.pop();
				s.push(front - back);
			}
			else if (postfix[i] == '*')
			{
				back = s.top();
				s.pop();
				front = s.top();
				s.pop();
				s.push(front * back);
			}
			else
			{
				back = s.top();
				s.pop();
				front = s.top();
				s.pop();
				s.push(front / back);
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top() << "\n";

	return 0;
}