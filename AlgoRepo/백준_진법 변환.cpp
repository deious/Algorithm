#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, num = 1, ans = 0;
	string B;
	cin >> B >> N;
	int len = B.size();
	char c;

	for (int i = len - 1; i >= 0; i--)
	{
		c = B[i];

		if (c >= 'A' && c <= 'Z')
			ans += (c - '7') * num;
		else
			ans += (c - '0') * num;

		num *= N;
	}

	cout << ans << "\n";

	return 0;
}