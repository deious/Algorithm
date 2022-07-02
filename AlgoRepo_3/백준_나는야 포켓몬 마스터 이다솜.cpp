#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	string s, s1;

	map<string, string> m;
	for (int i = 1; i <= N; i++)
	{
		cin >> s;
		s1 = to_string(i);
		m.insert({ s, s1 });
		m.insert({ s1, s });
	}

	for (int i = 0; i < M; i++)
	{
		cin >> s;
		if (m.find(s) != m.end())
			cout << m[s] << "\n";
	}

	return 0;
}