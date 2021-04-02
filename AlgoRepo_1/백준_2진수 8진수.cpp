#include <iostream>
#include <vector>
#include <string>

using namespace std;

char ans[3333334];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;

	cin >> s;
	int len = s.size(), cal = 1, count = 0, cIndex = 0, cLen;
	int temp = 0;
	vector<int> v(len);

	for (int i = 0; i < len; i++)
		v[i] = s[i] - '0';

	cIndex = (len - 1) / 3;
	cLen = cIndex;

	for (int i = len - 1; i >= 0; i--)
	{
		temp += v[i] * cal;
		cal *= 2;
		count++;
		if (count == 3)
		{
			count = 0;
			cal = 1;
			ans[cIndex--] = temp + '0';
			temp = 0;
		}
	}

	if (temp)
		ans[cIndex] = temp + '0';
	else if(len <= 2 && temp == 0)
		ans[cIndex] = temp + '0';

	for (int i = 0; i <= cLen; i++)
		cout << ans[i];
	cout << "\n";

	return 0;
}