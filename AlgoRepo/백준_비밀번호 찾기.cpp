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

	map<string, string> m;
	string s, s1;

	for (int i = 0; i < N; i++)
	{
		cin >> s >> s1;
		m[s] = s1;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> s;
		cout << m[s] << "\n";
	}

	return 0;
}