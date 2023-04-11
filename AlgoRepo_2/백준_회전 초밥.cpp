#include <iostream>

using namespace std;

int sushi[3000001];
int check[3001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, d, k, c;
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++)
	{
		cin >> sushi[i];
	}

	int s = 0, e = 0, maxCnt = 0, temp = 0, answer = 0;
	while (s < N - 1)
	{
		if (temp != k)
		{
			if (check[sushi[e]] == 0) 
			{
				maxCnt++;
			}

			check[sushi[e]]++;
			e++;
			temp++;

			if (temp == k) {
				if (check[c] == 0) 
				{
					maxCnt++;
				}

				check[c]++;
			}
		}
		else 
		{
			if (check[sushi[s]] == 1) 
			{
				maxCnt--;
			}
			check[sushi[s]]--;
			s++;

			if (check[sushi[e]] == 0) 
			{
				maxCnt++;
			}

			check[sushi[e]]++;

			e++;
			if (e >= N) 
			{
				e = 0;
			}
		}

		if (answer < maxCnt) 
		{
			answer = maxCnt;
		}
	}

	cout << answer << "\n";

	return 0;
}