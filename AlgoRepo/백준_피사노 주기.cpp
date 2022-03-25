#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int P, N, M;
	cin >> P;

	while (P--)
	{
		cin >> N >> M;
		
		vector<int> v;
		v.push_back(0);
		v.push_back(1);

		int count = 2;
		while (true)
		{
			v.push_back((v[count - 1] + v[count - 2]) % M);

			if (v[count] % M == 1 && v[count - 1] % M == 0)
			{
				cout << N << " " << count - 1 << "\n";
				break;
			}
			count++;
		}
	}

	return 0;
}