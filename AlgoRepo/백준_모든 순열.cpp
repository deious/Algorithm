#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) v[i] = i + 1;

	do
	{
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << "\n";
	}
	while (next_permutation(v.begin(), v.end()));

	return 0;
}