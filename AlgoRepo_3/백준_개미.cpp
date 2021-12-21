#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() 
{
	int N1, N2, T;
	cin >> N1 >> N2;

	string s, s1;
	cin >> s >> s1 >> T;

	reverse(s.begin(), s.end());
	string ans = s + s1;
	int len = N1 + N2 - 1;

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < len; j++) 
		{
			if (s.find(ans[j]) != string::npos && s1.find(ans[j + 1]) != string::npos) 
			{
				swap(ans[j], ans[j + 1]);
				j++;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}