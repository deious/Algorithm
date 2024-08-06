#include <iostream>

using namespace std;

int arr[100001];
bool check[100001];

int n, s, ans = 0;

bool InRange(int x)
{
	return x >= 1 && x <= n;
}

void Calculate(int num)
{
	int left = num - arr[num];
	int right = num + arr[num];

	if (InRange(left) && !check[left])
	{
		ans++;
		check[left] = true;
		Calculate(left);
	}

	if (InRange(right) && !check[right])
	{
		ans++;
		check[right] = true;
		Calculate(right);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	ans++;
	cin >> s;
	check[s] = true;
	Calculate(s);

	cout << ans << "\n";

	return 0;
}