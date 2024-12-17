#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string A, B;
	cin >> A >> B;

	for (int i = 2; i >= 0; i--)
	{
		if (A[i] > B[i])
		{
			for (int j = 2; j >= 0; j--)
			{
				cout << A[j];
			}

			break;
		}
		else if (A[i] < B[i])
		{
			for (int j = 2; j >= 0; j--)
			{
				cout << B[j];
			}

			break;
		}
		else
		{
			continue;
		}
	}

	return 0;
}