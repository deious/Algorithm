#include <iostream>
#include <string>

using namespace std;

int N;
bool flag = false;

void Calculate(string s, int num)
{
	if (flag || num > N)
		return;

	int len = s.size();
	for (int i = 1; i <= len / 2; i++)
	{
		if (s.substr(len - i, i) == s.substr(len - (i * 2), i))
		{
			return;
		}
	}

	if (num == N)
	{
		flag = true;
		cout << s << "\n";
		return;
	}
	else
	{
		Calculate(s + '1', len + 1);
		Calculate(s + '2', len + 1);
		Calculate(s + '3', len + 1);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	Calculate("", 0);

	return 0;
}