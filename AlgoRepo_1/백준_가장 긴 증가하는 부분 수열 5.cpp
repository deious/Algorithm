#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int arr[1000001];
int temp[1000001];
int N;

pair<int, int> v[1000001];

int LIS()
{
	int index = 0;
	temp[index] = arr[0];
	v[0] = { 0, arr[0] };

	for (int i = 1; i < N; i++)
	{
		if (temp[index] < arr[i])
		{
			temp[++index] = arr[i];
			v[i] = { index, arr[i] };
		}
		else
		{
			int tIndex = lower_bound(temp, temp + index, arr[i]) - temp;
			temp[tIndex] = arr[i];
			v[i] = { tIndex, arr[i] };
		}
	}

	return index;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int len = LIS();
	cout << len + 1 << "\n";

	stack<int> s;

	for (int i = N - 1; i >= 0; i--)
	{
		if (v[i].first == len)
		{
			s.push(v[i].second);
			len--;
		}
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}