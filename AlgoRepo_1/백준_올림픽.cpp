#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(tuple<int, int, int, int> a, tuple<int, int, int, int> b)
{
	if (get<1>(a) > get<1>(b))
		return true;
	else if (get<1>(a) == get<1>(b))
	{
		if (get<2>(a) > get<2>(b))
			return true;
		else if (get<2>(a) == get<2>(b))
		{
			if (get<3>(a) > get<3>(b))
				return true;
		}
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<tuple<int, int, int, int>> v(N);
	int a, b, c, d;
	
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c >> d;
		v[i] = { a,b,c,d };
	}

	sort(v.begin(), v.end(), cmp);

	int ranking = 1;
	if (get<0>(v[0]) == K)
	{
		cout << ranking << "\n";
		return 0;
	}

	int accumulate = 0;
	for (int i = 1; i < N; i++)
	{
		if (get<1>(v[i - 1]) != get<1>(v[i]) || get<2>(v[i - 1]) != get<2>(v[i]) || get<3>(v[i - 1]) != get<3>(v[i]))
		{
			ranking = ranking + accumulate + 1;
			accumulate = 0;
		}
		else
			accumulate++;

		if (get<0>(v[i]) == K)
		{
			cout << ranking << "\n";
			return 0;
		}
	}
}