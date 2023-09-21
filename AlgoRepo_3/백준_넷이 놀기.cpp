#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, A, B;
	cin >> N >> A >> B;

	vector<pair<int, int>> v(N);
	set<pair<int, int>> s;

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
		s.insert({ v[i].first, v[i].second });
	}

	int a, b, answer = 0;
	for (int i = 0; i < N; i++)
	{
		a = v[i].first;
		b = v[i].second;

		if (s.find({ a + A, b }) == s.end() || s.find({ a, b + B }) == s.end() || s.find({ a + A, b + B }) == s.end())
		{
			continue;
		}

		answer++;
	}

	cout << answer << "\n";

	return 0;
}