#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	string s = "", ans = "";
	int len = 0;
	while (T--)
	{
		ans = "";
		cin >> s;
		len = s.size();
		ans += s[0];
		ans += s[len - 1];
		cout << ans << "\n";
	}

	return 0;
}