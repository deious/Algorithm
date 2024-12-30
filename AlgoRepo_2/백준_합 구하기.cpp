#include <iostream>

using namespace std;

int arr[100001];
int sum[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}

	cin >> M;
	int a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}

	return 0;
}