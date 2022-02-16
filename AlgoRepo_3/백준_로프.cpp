#include <iostream>
#include <algorithm>

using namespace std;

int rope[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> rope[i];

	sort(rope, rope + N, greater<int>());

	int answer = 0;
	for (int i = 0; i < N; i++)
		answer = max(answer, rope[i] * (i + 1));

	cout << answer << "\n";

	return 0;
}