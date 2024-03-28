#include <iostream>
#include <map>

using namespace std;

struct Node
{
	char left;
	char right;
};

map<char, Node> m;

void PreOrder(char node)
{
	if (node == '.')
	{
		return;
	}

	cout << node;
	PreOrder(m[node].left);
	PreOrder(m[node].right);
}

void InOrder(char node)
{
	if (node == '.')
	{
		return;
	}

	InOrder(m[node].left);
	cout << node;
	InOrder(m[node].right);
}

void PostOrder(char node)
{
	if (node == '.')
	{
		return;
	}

	PostOrder(m[node].left);
	PostOrder(m[node].right);
	cout << node;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	char node, left, right;

	for (int i = 0; i < n; i++)
	{
		cin >> node >> left >> right;
		m[node].left = left;
		m[node].right = right;
	}

	PreOrder('A');
	cout << "\n";

	InOrder('A');
	cout << "\n";

	PostOrder('A');

	return 0;
}