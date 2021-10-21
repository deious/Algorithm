#include <iostream>
#include <string>

using namespace std;

string s[50];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i];

	string answer = "";
	int len = s[0].size();
	char c;
	bool check = false;
	for (int i = 0; i < len; i++)
	{
		c = s[0][i];
		check = false;

		for (int j = 1; j < n; j++)
		{
			if (s[j][i] == c)
				continue;
			else
			{
				check = true;
				break;
			}
		}

		if (check)
			answer.push_back('?');
		else
			answer.push_back(c);
	}

	len = answer.size();
	for (int i = 0; i < len; i++)
		cout << answer[i];
}