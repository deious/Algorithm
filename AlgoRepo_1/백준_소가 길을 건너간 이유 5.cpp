#include <iostream>
#include <algorithm>

using namespace std;

bool check[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, B, K;
	cin >> N >> K >> B;

	int temp = 0;
	for (int i = 1; i <= B; i++)
	{
		cin >> temp;
		check[temp] = true;
	}

	int cnt = 0;
	for (int i = 1; i <= K; i++)
	{
		cnt += check[i];
	}

	int ans = cnt;

	int j = 1;
	for (int i = K + 1; i <= N; i++)
	{
		cnt += check[i];
		cnt -= check[j++];
		ans = min(ans, cnt);
	}

	cout << ans << "\n";

	return 0;
}