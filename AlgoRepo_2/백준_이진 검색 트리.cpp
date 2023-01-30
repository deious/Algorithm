#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* Insert(Node* node, int data)
{
	if (node == NULL)
	{
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}
	else if (data < node->data)
	{
		node->left = Insert(node->left, data);
	}
	else
	{
		node->right = Insert(node->right, data);
	}

	return node;
}

void PostOrder(Node* node)
{
	if (node->left != NULL)
	{
		PostOrder(node->left);
	}

	if (node->right != NULL)
	{
		PostOrder(node->right);
	}

	cout << node->data << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int data;
	Node* tree = NULL;

	while (cin >> data)
	{
		tree = Insert(tree, data);
	}

	PostOrder(tree);

	return 0;
}