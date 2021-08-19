#include <iostream>
#include <algorithm>

using namespace std;

struct info 
{
	int send, receive, box;
};

info arr[10001];
int capacity[10001];

bool cmp(info a, info b) 
{
	if (a.receive < b.receive)
		return true;
	else if (a.receive == b.receive)
	{
		if (a.send < b.send)
			return true;
	}

	return false;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, C, M;
	cin >> N >> C >> M;

	for (int i = 0; i < M; i++)
		cin >> arr[i].send >> arr[i].receive >> arr[i].box;

	sort(arr, arr + M, cmp); 

	int ans = 0;
	for (int i = 0; i < M; i++) 
	{
		int maxBox = 0;
		for (int j = arr[i].send; j < arr[i].receive; j++) 
			maxBox = max(capacity[j], maxBox);

		int temp = min(arr[i].box, C - maxBox);
		ans += temp;

		for (int j = arr[i].send; j < arr[i].receive; j++)
			capacity[j] += temp;
	}

	cout << ans << "\n";

	return 0;
}