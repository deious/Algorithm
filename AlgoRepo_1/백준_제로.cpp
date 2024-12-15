#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K, num;
	cin >> K;

	stack<int> s;
	for (int i = 0; i < K; i++)
	{
		cin >> num;
		if (num == 0)
		{
			s.pop();
		}
		else
		{
			s.push(num);
		}
	}

	int ans = 0;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		ans += s.top();
		s.pop();
	}

	cout << ans << "\n";
	
	return 0;
}