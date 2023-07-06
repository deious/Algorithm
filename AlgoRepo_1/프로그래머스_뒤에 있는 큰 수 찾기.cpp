#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	stack<int> st;
	int len = numbers.size();

	for (int i = len - 1; i >= 0; i--)
	{
		if (st.empty())
		{
			st.push(numbers[i]);
			answer.push_back(-1);
		}
		else
		{
			while (!st.empty())
			{
				if (st.top() > numbers[i])
				{
					answer.push_back(st.top());
					st.push(numbers[i]);
					break;
				}
				st.pop();
			}

			if (st.empty())
			{
				st.push(numbers[i]);
				answer.push_back(-1);
			}
		}
	}

	reverse(answer.begin(), answer.end());
	return answer;
}