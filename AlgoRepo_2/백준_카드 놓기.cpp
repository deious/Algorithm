#include <iostream>
#include <string>
#include <set>

using namespace std;

int n, k;
set<int> s;
int arr[10];
bool check[10];

void DFS(int cnt, int pos, string str)
{
	if (cnt == k)
	{
		int num = stoi(str);
		s.insert(num);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			DFS(cnt + 1, i, str + to_string(arr[i]));
			check[i] = false;
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	DFS(0, 0, "");

	cout << s.size() << "\n";

	return 0;
}