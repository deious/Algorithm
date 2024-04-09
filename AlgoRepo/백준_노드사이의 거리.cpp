#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v[1001];
bool check[1001];
bool allEnd = false;
int ans = 0;

void Distance(int start, int end, int len)
{
	if (allEnd)
	{
		return;
	}

	if (start == end)
	{
		allEnd = true;
		ans = len;
		return;
	}

	check[start] = true;

	for (int i = 0; i < v[start].size(); i++)
	{
		int next = v[start][i].first;
		int roadLen = v[start][i].second;
		if (!check[next])
		{
			check[next] = true;
			Distance(next, end, len + roadLen);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	int from, to, len;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> from >> to >> len;
		v[from].push_back({ to, len });
		v[to].push_back({ from, len });
	}

	int start, end;
	for (int i = 0; i < M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			check[j] = false;
		}

		cin >> start >> end;
		Distance(start, end, 0);
		cout << ans << "\n";
		allEnd = false;
	}

	return 0;
}