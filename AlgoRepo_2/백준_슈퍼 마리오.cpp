#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	int sum = arr[0];
	int answer = sum;

	for (int i = 1; i < 10; i++)
	{
		sum += arr[i];
		abs(100 - sum) <= abs(100 - answer) ? answer = sum : answer;
	}

	cout << answer << "\n";

	return 0;
}