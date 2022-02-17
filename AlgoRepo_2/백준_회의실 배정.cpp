#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> v;
	int a, b;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ b, a });
	}

	sort(v.begin(), v.end());

	int endTime = v[0].first;
	int answer = 1;

	for (int i = 1; i < N; i++)
	{
		if (v[i].second >= endTime)
		{
			answer++;
			endTime = v[i].first;
		}
	}

	cout << answer << "\n";

	return 0;
}