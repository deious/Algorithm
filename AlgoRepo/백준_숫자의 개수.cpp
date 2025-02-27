#include <iostream>
#include <string>

using namespace std;

int countArr[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	A *= B * C;

	string s = to_string(A);

	int len = s.size();

	for (int i = 0; i < len; i++)
	{
		countArr[s[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << countArr[i] << "\n";
	}

	return 0;
}