#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool Calculate(vector<int> &v, int findNum)
{
	int st = 0, ed = v.size() - 1;
	
	while (st <= ed)
	{
		int mid = (st + ed) / 2;
		if (v[mid] == findNum)
		{
			return true;
		}
		else if (v[mid] < findNum)
		{
			st = mid + 1;
		}
		else
		{
			ed = mid - 1;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		vector<int> v(N);

		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int ans = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (abs(v[i] + v[j]) % 2 == 0 && (Calculate(v, (v[i] + v[j]) / 2)))
				{
					ans++;
				}
			}
		}

		cout << ans << "\n";
	}
}