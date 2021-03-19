#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	stack<int> s;

	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	vector<int> ans(N, -1);

	for (int i = 0; i < N; i++) 
	{
		while (!s.empty() && v[s.top()] < v[i]) 
		{
			ans[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
	
	cout << "\n";

	return 0;
}