#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
	int x, y, num;
	node *left;
	node *right;
};

bool Cmp(node a, node b)
{
	if (a.y == b.y)
		return a.x < b.x;

	return a.y > b.y;
}

void AddNode(node *parent, node *child)
{
	if (child->x < parent->x)
	{
		if (parent->left == NULL)
			parent->left = child;
		else
			AddNode(parent->left, child);
	}
	else
	{
		if (parent->right == NULL)
			parent->right = child;
		else
			AddNode(parent->right, child);
	}
}

void PreOrder(vector<int> &answer, node *nd)
{
	if (nd == NULL)
		return;
	answer.push_back(nd->num);
	PreOrder(answer, nd->left);
	PreOrder(answer, nd->right);

	return;
}

void PostOrder(vector<int> &answer, node *nd)
{
	if (nd == NULL)
		return;
	PostOrder(answer, nd->left);
	PostOrder(answer, nd->right);
	answer.push_back(nd->num);

	return;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer = { {},{} };
	vector<node> nd;
	node *root;

	int len = nodeinfo.size();

	for (int i = 0; i < len; i++)
	{
		node tNode;
		tNode.x = nodeinfo[i][0];
		tNode.y = nodeinfo[i][1];
		tNode.num = i + 1;
		nd.push_back(tNode);
	}

	sort(nd.begin(), nd.end(), Cmp);

	root = &nd[0];

	for (int i = 1; i < len; i++)
		AddNode(root, &nd[i]);

	PreOrder(answer[0], root);
	PostOrder(answer[1], root);

	return answer;
}