#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x, n;
	while (1)
	{
		if (cin >> x)
		{
			x *= 10000000;
			cin >> n;

			vector<int> v(n);
			for (int i = 0; i < n; i++)
				cin >> v[i];

			sort(v.begin(), v.end());

			bool check = false;
			int left = 0, right = n - 1;
			while (left < right)
			{
				if (v[left] + v[right] == x)
				{
					cout << "yes " << v[left] << " " << v[right] << "\n";
					check = true;
					break;
				}
				else if (v[left] + v[right] > x)
					right--;
				else
					left++;
			}

			if (!check)
				cout << "danger\n";
		}
		else
			break;
	}
}