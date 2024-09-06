#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s, s1;
	getline(cin, s);
	getline(cin, s1);

	int len = s.size(), len1 = s1.size();

	int ans = 0;
	for (int i = 0; i < len;)
	{
		string temp = s.substr(i, len1);

		if (temp.compare(s1) == 0)
		{
			ans++;
			i += len1;
		}
		else
		{
			i++;
		}
	}

	cout << ans << "\n";

	return 0;
}