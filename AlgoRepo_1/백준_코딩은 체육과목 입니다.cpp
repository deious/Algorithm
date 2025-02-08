#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	string s = "long", s1 = "int";
	int len = N / 4;

	for (int i = 0; i < len; i++)
	{
		cout << s << " ";
	}

	cout << s1;

	return 0;
}