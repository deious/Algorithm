#include <iostream>

using namespace std;

bool check[2000001];
int S[20];
int N;

void solve(int start, int index)
{
	check[start] = true;

	if (index == N || index > N)
		return;

	for(int i = index; i < N; i++)
		solve(start + S[i], i + 1);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> S[i];

	check[0] = true;
	for (int i = 0; i < N; i++)
		solve(S[i], i + 1);


	int start = 0;
	while (1)
	{
		if (!check[start]) 
		{
			cout << start << "\n";
			return 0;
		}
		start++;
	}

	return 0;
}