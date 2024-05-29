#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[5000];
int check[5000][5000];

int Calculate(int s, int e)
{
	if (s > e)
	{
		return 0;
	}

	int& res = check[s][e];

	if (res != -1)
	{
		return res;
	}

	if (arr[s] == arr[e])
	{
		res = Calculate(s + 1, e - 1);
	}
	else
	{
		res = min(1 + Calculate(s + 1, e), 1 + Calculate(s, e - 1));
	}

	return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	memset(check, -1, sizeof(check));
	cout << Calculate(0, N - 1) << "\n";

	return 0;
}