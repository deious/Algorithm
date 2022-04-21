#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	set<string> s;
	string str;
	vector<string> v;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		s.insert(str);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (!s.insert(str).second)
			v.push_back(str);
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (auto au : v)
		cout << au << "\n";

	return 0;
}