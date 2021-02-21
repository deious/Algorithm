#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int count = 0, piece = 0;
	string s;
	cin >> s;

	int len = s.size();

	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
			count++;
		else
		{
			count--;
			if (s[i - 1] == '(')
				piece += count;
			else
				piece++;
		}
	}

	cout << piece << "\n";

	return 0;
}