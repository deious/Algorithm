#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B, C, N;
	cin >> A >> B >> C >> N;
	int sum = 0;

	for (int i = 0; i <= 300; i += A)
	{
		sum = 0;
		for (int j = 0; j <= 300; j += B)
		{
			for (int k = 0; k <= 300; k += C)
			{
				sum = i + j + k;
				if (sum == N)
				{
					cout << "1\n";
					return 0;
				}
			}
		}
	}
	
	cout << "0\n";

	return 0;
}