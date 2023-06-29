#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool check[201][201];

string a, b, c;

bool DFS(int fIndex, int sIndex, int tIndex)
{
	if (tIndex == c.size())
		return true;

	if (check[fIndex][sIndex])
		return false;

	check[fIndex][sIndex] = true;

	if (c[tIndex] == a[fIndex] && c[tIndex] == b[sIndex])
		return DFS(fIndex + 1, sIndex, tIndex + 1) || DFS(fIndex, sIndex + 1, tIndex + 1);
	else if (c[tIndex] == a[fIndex])
		return DFS(fIndex + 1, sIndex, tIndex + 1);
	else if (c[tIndex] == b[sIndex])
		return DFS(fIndex, sIndex + 1, tIndex + 1);
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		bool flag = false;
		memset(check, false, sizeof(check));

		flag = DFS(0, 0, 0);
		if (flag)
			cout << "Data set " << i + 1 << ": yes\n";
		else
			cout << "Data set " << i + 1 << ": no\n";
	}

	return 0;
}