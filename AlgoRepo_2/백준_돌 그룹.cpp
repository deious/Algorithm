#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	if ((A + B + C) % 3 != 0)
	{
		cout << "0\n";
		return 0;
	}

	vector<int> v;
	v.push_back(A);
	v.push_back(B);
	v.push_back(C);
	sort(v.begin(), v.end());
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(v[0], v[1]), v[2]));
	set<pair<pair<int, int>,int>> s;
	s.insert(make_pair(make_pair(v[0], v[1]), v[2]));
	v.clear();

	while (!q.empty())
	{
		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (a == b && b == c)
		{
			cout << "1\n";
			return 0;
		}

		v.push_back(2 * a);
		v.push_back(b - a);
		v.push_back(c);
		sort(v.begin(), v.end());

		if (s.insert(make_pair(make_pair(v[0], v[1]), v[2])).second)
			q.push(make_pair(make_pair(v[0], v[1]), v[2]));
		v.clear();

		v.push_back(2 * a);
		v.push_back(b);
		v.push_back(c - a);
		sort(v.begin(), v.end());


		if (s.insert(make_pair(make_pair(v[0], v[1]), v[2])).second)
			q.push(make_pair(make_pair(v[0], v[1]), v[2]));
		v.clear();

		v.push_back(a);
		v.push_back(2 * b);
		v.push_back(c - b);
		sort(v.begin(), v.end());

		if (s.insert(make_pair(make_pair(v[0], v[1]), v[2])).second)
			q.push(make_pair(make_pair(v[0], v[1]), v[2]));
		v.clear();
	}

	cout << "0\n";
	return 0;
}