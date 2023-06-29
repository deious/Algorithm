#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int arr[101];
bool check[101];

vector<int> v;

void DFS(int start, int current)
{
	if (!check[current])
	{
		check[current] = true;
		DFS(start, arr[current]);
	}
	else if (start == current)
	{
		v.push_back(start);
		return;
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
	{
		memset(check, false, sizeof(check));
		DFS(i, i);
	}

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;
}