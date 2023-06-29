#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

bool check[10001];
bool visit[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		memset(check, false, sizeof(check));
		memset(visit, false, sizeof(visit));

		check[1] = true;
		for (int i = 2; i * i <= 10000; i++)
		{
			if (!check[i])
			{
				for (int j = i * i; j <= 10000; j += i)
					check[j] = true;
			}
		}
		queue<pair<int, int>> q;
		int start, end;
		cin >> start >> end;
		q.push(make_pair(start, 0));
		while (!q.empty())
		{
			int st = q.front().first;
			int count = q.front().second;
			q.pop();

			visit[st] = true;

			if (st == end)
			{
				cout << count << "\n";
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					string s = to_string(st);
					s[i] = j + '0';
					int n = stoi(s);

					if (!visit[n] && !check[n] && n >= 1000)
						q.push(make_pair(n, count + 1));
				}
			}
		}

		if (!visit[end])
			cout << "Impossible" << "\n";
	}

	return 0;
}