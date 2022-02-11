#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	set<int> s;
	int a;

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		s.insert(a);
	}

	for (auto au : s)
		cout << au << "\n";

	return 0;
}