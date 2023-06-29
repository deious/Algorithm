#include <iostream>

using namespace std;

int check[240000];
int P;

void DFS(int n)
{
	check[n]++;
	
	if (check[n] == 3)
		return;

	int num = 0, temp = 0;

	while (n)
	{
		int temp1 = 1;
		temp = n % 10;
		for (int i = 0; i < P; i++)
			temp1 *= temp;
		num += temp1;
		n /= 10;
	}
	DFS(num);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int A, ans = 0;
	cin >> A >> P;

	DFS(A);

	for (int i = 0; i < 240000; i++)
	{
		if (check[i] == 1)
			ans++;
	}

	cout << ans << "\n";

	return 0;
}