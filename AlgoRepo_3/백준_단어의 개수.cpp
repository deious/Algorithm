#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	int cnt = 1;

	getline(cin, s);

	int len = s.size();

	for (int i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			cnt++;
		}
	}

	if (s[0] == ' ')
	{
		cnt--;
	}

	if (s[len - 1] == ' ')
	{
		cnt--;
	}

	cout << cnt << "\n";

	return 0;
}