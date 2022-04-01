#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string S;
	cin >> S;

	vector<string> v;

	int len = S.size();
	for (int i = 0; i < len; i++)
	{
		string s;
		s = S.substr(i, len - i);
		v.push_back(s);
	}

	sort(v.begin(), v.end());

	for (auto au : v)
		cout << au << "\n";

	return 0;
}