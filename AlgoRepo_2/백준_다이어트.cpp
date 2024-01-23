#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int G;
	cin >> G;

	int start = 1, end = 1;
	vector<int> ans;

	while (end < G)
	{
		int weight = end * end - start * start;

		if (weight == G)
		{
			ans.push_back(end);
			start++;
		}
		else if (weight < G)
		{
			end++;
		}
		else
		{
			start++;
		}
	}

	if (ans.empty())
	{
		cout << "-1\n";
	}
	else
	{
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << "\n";
		}
	}

	return 0;
}