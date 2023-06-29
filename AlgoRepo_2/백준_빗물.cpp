#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int H, W;
	cin >> H >> W;

	vector<int> v(W);
	for (int i = 0; i < W; i++)
	{
		cin >> v[i];
	}

	int answer = 0;
	stack<int> s;
	int temp = 0;

	for (int i = 0; i < W; i++)
	{

		if (temp == 0)
		{
			temp = v[i];
		}
		else
		{
			if (v[i] < temp)
			{
				s.push(v[i]);
			}
			else
			{
				while (!s.empty())
				{
					answer += temp - s.top();
					s.pop();
				}
				temp = v[i];
			}
		}
	}

	int last = 0;
	if (!s.empty())
	{
		last = s.top();
		s.pop();
	}

	while (!s.empty())
	{
		if (last < s.top())
		{
			last = s.top();
			s.pop();
		}
		else
		{
			answer += last - s.top();
			s.pop();
		}
	}

	cout << answer << "\n";

	return 0;
}