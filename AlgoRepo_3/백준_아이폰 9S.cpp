#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int arr[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	set<int> s;
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		s.insert(arr[i]);
	}

	int ans = 0;

	for (auto au : s)
	{	
		int temp = arr[0], cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (arr[j] == au)
			{
				continue;
			}
			else if (arr[j] == temp)
			{
				cnt++;
				ans = max(ans, cnt);
			}
			else
			{
				temp = arr[j];
				cnt = 1;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}