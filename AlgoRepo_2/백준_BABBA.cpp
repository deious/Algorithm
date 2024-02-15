#include <iostream>

using namespace std;

int A[46], B[46];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int K;
	cin >> K;

	A[1] = 0;
	B[1] = 1;

	for (int i = 2; i <= K; i++)
	{
		A[i] = B[i - 1];
		B[i] = A[i - 1] + B[i - 1];
	}

	cout << A[K] << " " << B[K] << "\n";

	return 0;
}