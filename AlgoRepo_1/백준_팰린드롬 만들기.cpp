#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alphabet[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int len = s.size();
	int oddCount = 0, middleIndex = - 1;

	for (int i = 0; i < len; i++)
		alphabet[s[i] - 'A']++;

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] > 0)
		{
			if (alphabet[i] % 2)
			{
				oddCount++;
				middleIndex = i;
				alphabet[i]--;
			}

			if (oddCount > 1)
			{
				cout << "I'm Sorry Hansoo\n";
				return 0;
			}
		}
	}

	string temp = "";
	s = "";

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i])
		{
			len = alphabet[i] / 2;
			for (int j = 0; j < len; j++)
				s += ('A' + i);
		}
	}

	temp = s;
	reverse(temp.begin(), temp.end());

	if (middleIndex != -1)
		s += (middleIndex + 'A');

	s += temp;

	cout << s << "\n";

	return 0;
}