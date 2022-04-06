#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, L;
	cin >> N >> L;

	vector<pair<int, int>> v;
	int a, b;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	int answer = 0, pos = 0, temp = 0;
	for (int i = 0; i < N; i++)
	{
		if (pos >= v[i].second)
			continue;

		pos = max(pos, v[i].first);
		if ((v[i].second - pos) % L == 0)
		{
			temp = ((v[i].second - pos) / L);
			answer += temp;
			pos += temp * L;
		}
		else
		{
			temp = (v[i].second - pos) / L + 1;
			answer += temp;
			pos += temp * L;
		}
	}

	cout << answer << "\n";

	return 0;
}