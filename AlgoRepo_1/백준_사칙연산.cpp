#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B;
	cin >> A >> B;

	cout << A + B << "\n" << A - B << "\n" << A * B << "\n" << A / B << "\n" << A % B << "\n";

	return 0;
}