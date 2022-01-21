#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		pq.push(num);
	}

	int answer = 0;
	while (pq.size() != 1)
	{
		int temp = 0;
		temp += pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		pq.push(temp);
		answer += temp;
	}

	cout << answer << "\n";

	return 0;
}