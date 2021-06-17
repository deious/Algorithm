#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> v(N), v1(M);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	for (int i = 0; i < M; i++)
		cin >> v1[i];

	int num = 0, ans = 0;

	int vIndex = 0;
	int v1Index = 0;

	while (M--)
	{
		ans++;
		vIndex += v1[v1Index];
		if (vIndex >= N - 1)
		{
			cout << ans << "\n";
			return 0;
		}
		vIndex += v[vIndex];
		if (vIndex >= N - 1)
		{
			cout << ans << "\n";
			return 0;
		}
		v1Index++;
	}

	return 0;
}