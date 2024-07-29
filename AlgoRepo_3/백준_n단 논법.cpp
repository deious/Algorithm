#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int alpha[26];
bool endCheck = false;

bool DFS(int start, int end)
{
	if (start == -1)
	{
		return false;
	}

	if (endCheck)
	{
		return true;
	}

	if (start == end)
	{
		endCheck = true;
		return true;
	}
	else
	{
		return DFS(alpha[start], end);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;

	string s;
	char start, end;

	memset(alpha, -1, sizeof(alpha));

	for (int i = 0; i < n; i++)
	{
		cin >> start >> s >> end;
		alpha[start - 'a'] = end - 'a';
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		endCheck = false;
		cin >> start >> s >> end;
		if (DFS(start - 'a', end - 'a'))
		{
			cout << "T\n";
		}
		else
		{
			cout << "F\n";
		}
	}

	return 0;
}