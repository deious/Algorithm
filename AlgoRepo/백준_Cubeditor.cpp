#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int CheckLength(string s)
{
	int len = s.size();
	vector<int> v(len, 0);

	int j = 0;
	for (int i = 1; i < len; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = v[j - 1];
		if (s[i] == s[j])
			v[i] = ++j;
	}
	sort(v.begin(), v.end());
	
	return v[len - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int answer = 0, len = s.size();;
	for (int i = 0; i < len; i++)
	{
		string ts = s.substr(i, len);
		int tAnswer = CheckLength(ts);
		answer = max(answer, tAnswer);
	}

	cout << answer << "\n";

	return 0;
}