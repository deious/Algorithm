#include <iostream>

using namespace std;

int inorder[100001];
int postorder[100001];
int index[100001];

void printPreorder(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd)
{
	if (inorderStart > inorderEnd || postorderStart > postorderEnd)
		return;

	int root = postorder[postorderEnd];
	cout << root << " ";
	
	printPreorder(inorderStart, index[root] - 1, postorderStart, postorderStart + (index[root] - inorderStart) - 1);
	printPreorder(index[root] + 1, inorderEnd, postorderStart + (index[root] - inorderStart), postorderEnd - 1);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> inorder[i];
		index[inorder[i]] = i;
	}

	for (int i = 0; i < N; i++)
		cin >> postorder[i];

	printPreorder(0, N - 1, 0, N - 1);

	return 0;
}