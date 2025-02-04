#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> A >> B;
		cout << "Case #" << i << ": " << A + B << "\n";
	}

	return 0;
}