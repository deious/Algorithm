#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s[1000];

int K, N;

bool cmp(string &s1, string &s2)
{
	return stoi(s1) > stoi(s2);
}

bool cmp1(string &s1, string &s2)
{
	return s1 + s2 > s2 + s1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> s[i];

	sort(s, s + K, cmp);

	for (int i = K; i < N; i++)
		s[i] = s[0];

	sort(s, s + N, cmp1);

	string answer = "";
	for (int i = 0; i < N; i++)
		answer += s[i];

	cout << answer << "\n";

	return 0;
}