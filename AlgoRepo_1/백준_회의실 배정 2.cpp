#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[25][3];
int N, ans;

void DFS(int cnt, int sum)
{
	if (cnt > N - 1) 
	{
		ans = max(ans, sum);
		return;
	}

	DFS(cnt + 1, sum);
	DFS(cnt + 2, sum + arr[cnt][2]);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	DFS(0, 0);

	cout << ans << endl;

	return 0;
}