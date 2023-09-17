#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int x;
	cin >> x;

	sort(v.begin(), v.end());

	int start = 0, end = n - 1, answer = 0;

	while (start < end)
	{
		if (v[start] + v[end] == x)
		{
			answer++;
			start++;
			end--;
		}
		else if (v[start] + v[end] > x)
		{
			end--;
		}
		else
		{
			start++;
		}
	}

	cout << answer << "\n";

	return 0;
}