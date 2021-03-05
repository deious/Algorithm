#include <iostream>
#include <algorithm>

using namespace std;

bool check[10];
int energy[10];
int N;

int calculate()
{
	int maxEnergy = 0;

	for (int i = 1; i < N - 1; i++)
	{
		if (check[i])
			continue;
		int left = i - 1;
		int right = i + 1;

		while (check[left] && left > 0)
			left--;
		while (check[right] && right < N - 1)
			right++;

		check[i] = true;
		maxEnergy = max(maxEnergy, energy[left] * energy[right] + calculate());
		check[i] = false;
	}

	return maxEnergy;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> energy[i];

	for (int i = N; i < 10; i++)
		check[i] = true;

	cout << calculate() << "\n";

	return 0;
}