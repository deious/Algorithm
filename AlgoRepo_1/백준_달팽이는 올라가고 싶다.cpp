#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, V;
	cin >> A >> B >> V;

	if ((V - A) % (A - B) == 0)
		cout << (V - A) / (A - B) + 1 << "\n";
	else
		cout << (V - A) / (A - B) + 2 << "\n";

	return 0;
}