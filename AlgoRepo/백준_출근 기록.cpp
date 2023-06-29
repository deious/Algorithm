#include <iostream>
#include <string>

using namespace std;

int abcCount[3];
bool dp[50][50][50][3][3];
char ans[50];

bool start(int a, int b, int c, int before1, int before2)
{
	if (a == abcCount[0] && b == abcCount[1] && c == abcCount[2]) 
		return true;

	if (dp[a][b][c][before1][before2]) 
		return false;

	dp[a][b][c][before1][before2] = true;

	if (a < abcCount[0]) 
	{		
		ans[a + b + c] = 'A';
		if (start(a + 1, b, c, 0, before1))
			return true;
	}
	if (b < abcCount[1]) 
	{
		ans[a + b + c] = 'B';
		if (before1 != 1) 
		{
			if (start(a, b + 1, c, 1, before1))
				return true;
		}
	}
	if (c < abcCount[2]) 
	{
		ans[a + b + c] = 'C';
		if (before1 != 2 && before2 != 2) 
		{
			if (start(a, b, c + 1, 2, before1))
				return true;
		}
	}
	return false;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;

	cin >> s;
	int len = s.size();

	for (int i = 0; i < len; i++) 
	{
		if (s[i] == 'A')
			abcCount[0]++;
		else if (s[i] == 'B')
			abcCount[1]++;
		else 
			abcCount[2]++;
	}
	if (start(0, 0, 0, 0, 0))
	{
		for (int i = 0; i < len; i++)
			cout << ans[i];
		cout << "\n";
	}
	else 
		cout << -1 << "\n";

	return 0;
}