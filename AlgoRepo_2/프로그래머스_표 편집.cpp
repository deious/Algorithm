#include <string>
#include <vector>
#include <stack>

using namespace std;

struct node {
	int num;
	node *prev;
	node *next;
	node(int n) :num(n), prev(NULL), next(NULL) {};
};

string solution(int n, int k, vector<string> cmd) {
	string answer(n, 'X');
	vector<node*> v(n);

	for (int i = 0; i < n; i++)
		v[i] = new node(i);

	v[n - 1]->prev = v[n - 2];
	v[0]->next = v[1];

	for (int i = 1; i < n - 1; i++)
	{
		v[i]->prev = v[i - 1];
		v[i]->next = v[i + 1];
	}

	int index = k;
	stack<int> s;

	for (auto au : cmd)
	{
		if (au[0] == 'U' || au[0] == 'D')
		{
			int n = stoi(au.substr(2));

			if (au[0] == 'U')
			{
				while (n--)
					index = v[index]->prev->num;
			}
			else
			{
				while (n--)
					index = v[index]->next->num;
			}
		}
		else if (au[0] == 'C')
		{
			s.push(index);
			if (v[index]->prev != NULL)
				v[index]->prev->next = v[index]->next;

			if (v[index]->next != NULL)
			{
				v[index]->next->prev = v[index]->prev;
				index = v[index]->next->num;
			}
			else
				index = v[index]->prev->num;

		}
		else if (au[0] == 'Z')
		{
			int tIndex = s.top();
			s.pop();

			if (v[tIndex]->prev != NULL)
				v[tIndex]->prev->next = v[tIndex];

			if (v[tIndex]->next != NULL)
				v[tIndex]->next->prev = v[tIndex];
		}
	}

	int leftIndex = index;
	int rightIndex = index;
	answer[index] = 'O';

	while (v[leftIndex]->prev != NULL)
	{
		leftIndex = v[leftIndex]->prev->num;
		answer[leftIndex] = 'O';
	}

	while (v[rightIndex]->next != NULL)
	{
		rightIndex = v[rightIndex]->next->num;
		answer[rightIndex] = 'O';
	}

	return answer;
}