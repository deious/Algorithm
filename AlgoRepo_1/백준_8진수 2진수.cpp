#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int len = s.size();
	vector<int> v(len * 3);
	int vIndex = 0;

	for(int i = 0; i < len; i++)
	{
		int n = s[i] - '0';

		if (n / 4 == 1)
		{
			v[vIndex++] = 1;
			n -= 4;
		}
		else
			v[vIndex++] = 0;

		if (n / 2 == 1)
		{
			v[vIndex++] = 1;
			n -= 2;
		}
		else
			v[vIndex++] = 0;

		if (n == 1)
			v[vIndex++] = 1;
		else
			v[vIndex++] = 0;
	}

	bool check = false;

	for (int i = 0; i < vIndex; i++)
	{
		if (i == 0)
		{
			if (v[i] == 0)
			{
				check = true;
				continue;
			}
		}
		else if (i == 1 && check)
		{
			if (v[i] == 0)
				continue;
		}

		cout << v[i];
	}
	cout << "\n";

	return 0;
}