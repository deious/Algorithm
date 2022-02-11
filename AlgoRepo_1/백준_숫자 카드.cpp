#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int a;
	set<int> s;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		s.insert(a);
	}

	int M;
	cin >> M;
	
	for (int i = 0; i < M; i++)
	{
		cin >> a;
		if (s.insert(a).second)
			cout << "0\n";
		else
			cout << "1\n";
	}

	return 0;
}