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

	vector<int> v;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	if (N % 2 == 0)
	{
		cout << v[N / 2 - 1] << "\n";
	}
	else
	{
		cout << v[N / 2] << "\n";
	}

	return 0;
}