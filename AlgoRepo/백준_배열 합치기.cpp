#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int temp = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		A.push_back(temp);
	}

	sort(A.begin(), A.end());

	int len = A.size();
	for (int i = 0; i < len; i++)
	{
		cout << A[i] << " ";
	}

	return 0;
}