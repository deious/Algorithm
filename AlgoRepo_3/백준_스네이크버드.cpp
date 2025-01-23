#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, L;
	cin >> N >> L;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++)
	{
		if (L >= v[i])
		{
			L++;
		}
		else
		{
			break;
		}
	}

	cout << L << "\n";

	return 0;
}