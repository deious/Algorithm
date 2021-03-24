#include <iostream>
#include <cstring>

using namespace std;

int S;
long long dp[51][51][51][51];
int Mod = 1000000007;

long long solution(int S, int a, int b, int c) 
{
	if (S == 0) 
	{
		if (a == 0 && b == 0 && c == 0)
			return 1;
		else
			return 0;
	}

	long long &album = dp[S][a][b][c];

	if (album != -1)
		return album;
	album = 0;

	album += solution(S - 1, a - 1, b, c);
	album += solution(S - 1, a, b - 1, c);
	album += solution(S - 1, a, b, c - 1);
	album += solution(S - 1, a - 1, b - 1, c);
	album += solution(S - 1, a - 1, b, c - 1);
	album += solution(S - 1, a, b - 1, c - 1);
	album += solution(S - 1, a - 1, b - 1, c - 1);
	album %= Mod;

	return album;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b, c;
	memset(dp, -1, sizeof(dp));
	cin >> S >> a >> b >> c;
	cout << solution(S, a, b, c) << "\n";

	return 0;
}