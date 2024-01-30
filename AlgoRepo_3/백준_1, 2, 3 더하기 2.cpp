#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, k;
int arr[3] = { 1, 2, 3 };
map<string, int> m;

void DFS(string s, int sum)
{
	for (int i = 0; i < 3; i++)
	{
		sum += arr[i];
		
		if (sum > n)
		{
			continue;
		}
		else if (sum == n)
		{
			m[s + to_string(arr[i])]++;
		}
		else
		{
			DFS(s + to_string(arr[i]) + "+", sum);
		}

		sum -= arr[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	DFS("", 0);
	int len = m.size();

	if (len < k)
	{
		cout << "-1\n";
		return 0;
	}

	int idx = 1;
	for (auto au : m)
	{
		if (idx == k)
		{
			cout << au.first << "\n";
			return 0;
		}
		idx++;
	}

	return 0;
}