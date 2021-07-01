#include <iostream>

using namespace std;

long long N, B;
long long ans[5][5];
long long arr[5][5];
long long temp[5][5];

void calculate(long long x[5][5], long long y[5][5])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				temp[i][j] += (x[i][k] * y[k][j]);
			}
			temp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			x[i][j] = temp[i][j];

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		ans[i][i] = 1;
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	while (B > 0)
	{
		if (B % 2)
			calculate(ans, arr);

		calculate(arr, arr);
		B /= 2;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}