#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, C = -1;
	cin >> A >> B;

	string s = to_string(A);
	sort(s.begin(), s.end());

	do
	{
		if (s[0] == '0')
		{
			continue;
		}

		int num = stoi(s);
		if (num > C && num < B)
		{
			C = num;
		}
	} while (next_permutation(s.begin(), s.end()));

	cout << C << "\n";

	return 0;
}