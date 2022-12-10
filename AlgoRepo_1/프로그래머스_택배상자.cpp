#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	queue<int> q;
	stack<int> s;

	for (int i = 0; i < order.size(); i++)
	{
		q.push(order[i]);
	}

	int index = 1;
	while (1)
	{
		if (!s.empty())
		{
			if (s.top() == q.front())
			{
				s.pop();
				q.pop();
				answer++;
			}
			else if (index > order.size())
			{
				break;
			}
		}

		if (!q.empty() && index <= order.size())
		{
			if (q.front() == index)
			{
				q.pop();
				answer++;
				index++;
			}
			else
			{
				s.push(index);
				index++;
			}
		}

		if (q.empty() && s.empty())
		{
			break;
		}
	}

	return answer;
}