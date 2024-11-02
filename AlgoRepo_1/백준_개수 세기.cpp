#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, v;
	vector<int> arr;

	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	cin >> v;

	sort(arr.begin(), arr.end());
	cout << upper_bound(arr.begin(), arr.end(), v) - lower_bound(arr.begin(), arr.end(), v) << "\n";

	return 0;
}