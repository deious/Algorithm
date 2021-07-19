#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long N, x, y;
	int K, Q;

	cin >> N >> K >> Q;

	for (int i = 0; i < Q; i++)
	{
		cin >> x >> y;
		long long distance = 0;

		if (K == 1)
			distance = abs(x - y);
		else
		{
			while (x != y)
			{
				if (x > y)
					x = (x - 2) / K + 1;
				else
					y = (y - 2) / K + 1;

				distance++;
			}
		}

		cout << distance << "\n";
	}

	return 0;
}