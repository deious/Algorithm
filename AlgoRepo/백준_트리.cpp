#include <iostream>
#include <vector>

using namespace std;

int K, answer = 0;
vector<int> tree[50];

int DFS(int num, int bro)
{
	if (num == K)
	{
		if (bro == 0)
			answer++;

		return 0;
	}

	if (tree[num].size() == 0)
		answer++;
	else
	{
		for (int i = 0; i < tree[num].size(); i++)
			DFS(tree[num][i], tree[num].size() - 1);
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int a, root;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == -1)
			root = i;
		else
			tree[a].push_back(i);
	}
	
	cin >> K;

	cout << DFS(root, 0) << "\n";

	return 0;
}