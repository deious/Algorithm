#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b)
{
	if (get<1>(a) == get<1>(b))
	{
		if (get<2>(a) == get<2>(b))
		{
			if (get<3>(a) == get<3>(b))
			{
				return get<0>(a) < get<0>(b);
			}

			return get<3>(a) > get<3>(b);
		}

		return get<2>(a) < get<2>(b);
	}

	return get<1>(a) > get<1>(b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<tuple<string, int, int, int>> v(N);

	string s;
	int a, b, c;

	for (int i = 0; i < N; i++)
	{
		cin >> s >> a >> b >> c;
		v[i] = { s, a ,b, c };
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < N; i++)
		cout << get<0>(v[i]) << "\n";

	return 0;
}