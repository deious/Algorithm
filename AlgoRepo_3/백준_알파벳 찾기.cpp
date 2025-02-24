#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alpha[26];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string S;
	cin >> S;

	fill(alpha, alpha + 26, -1);
	for (int i = 0; i < S.size(); i++)
	{
		if (alpha[S[i] - 'a'] == -1)
		{
			alpha[S[i] - 'a'] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << alpha[i] << " ";
	}

	return 0;
}