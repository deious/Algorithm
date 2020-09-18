#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int root[100];
vector<int> v;

bool checkCost(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int findRoot(int node)
{
    if(node == root[node]) return node;
    else return root[node] = findRoot(root[node]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int len = costs.size();
    
    sort(costs.begin(), costs.end(), checkCost);
    
    for(int i = 0; i < n; i++)
    {
        root[i] = i;
    }
    
    for(int i = 0; i < len; i++)
    {
        int start = findRoot(costs[i][0]);
        int end = findRoot(costs[i][1]);
        int cost = costs[i][2];
        
        if(start != end)
        {
            root[end] = start;
            answer += cost;
        }
    }
    
    return answer;
}