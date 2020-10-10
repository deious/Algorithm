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

	for (int i = 0; i < n; i++) cin >> v[i];

	if (next_permutation(v.begin(), v.end()))
	{
		for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			cout << *iter << " ";
		}
	}
	else cout << "-1\n";

	return 0;
}