#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	vector<int> v1 = v;
	sort(v1.begin(), v1.end());
	v1.erase(unique(v1.begin(), v1.end()), v1.end());

	for (int i = 0; i < N; i++)
	{
		auto iter = lower_bound(v1.begin(), v1.end(), v[i]);
		cout << iter - v1.begin() << " ";
	}
	
	cout << "\n";

	return 0;
}