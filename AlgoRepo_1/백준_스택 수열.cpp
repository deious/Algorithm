#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int num = 0;
	stack<int> s;
	vector<char> v;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		while (num < a)
		{
			num++;
			s.push(num);
			v.push_back('+');
		}

		if (s.top() == a)
		{
			s.pop();
			v.push_back('-');
		}
		else
		{
			cout << "NO\n";
			return 0;
		}
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}