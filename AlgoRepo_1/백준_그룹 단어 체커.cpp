#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	string s;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		bool check[26];
		memset(check, false, sizeof(check));
		bool checkEnd = true;
		int len = s.size();

		for (int j = 0; j < len; j++)
		{
			if (check[s[j] - 'a'] && s[j - 1] != s[j])
			{
				checkEnd = false;
				break;
			}

			if (check[s[j] - 'a'] && s[j - 1] == s[j])
			{
				continue;
			}

			if (!check[s[j] - 'a'])
			{
				check[s[j] - 'a'] = true;
			}
		}

		if (checkEnd)
		{
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}