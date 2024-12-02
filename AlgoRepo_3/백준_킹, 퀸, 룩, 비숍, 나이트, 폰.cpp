#include <iostream>

using namespace std;

int arr[6] = { 1, 1, 2, 2, 2, 8 };
int arr1[6];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num;
	for (int i = 0; i < 6; i++)
	{
		cin >> num;
		cout << arr[i] - num << " ";
	}

	return 0;
}