#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, ans = -2100000000;
string S;

int calculate(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	else
		return a * b;
}

void check(int index, int a)
{
	if (index >= N)
	{
		ans = max(ans, a);
		return;
	}

	char c = index > 0 ? S[index - 1] : '+';
	int temp = calculate(a, S[index] - '0', c);

	check(index + 2, temp);

	if (index < N - 2)
	{
		temp = calculate(S[index] - '0', S[index + 2] - '0', S[index + 1]);
		temp = calculate(a, temp, c);

		check(index + 4, temp);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S;

	check(0, 0);
	cout << ans << "\n";

	return 0;
}