#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &computers, vector<bool> &v, int n, int index)
{
    v[index] = true;
    
    for(int i = 0; i < n; i++)
    {
        if(!v[i] && computers[index][i])
        {
            dfs(computers, v, n, i);
        }
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> v(n, false);
    
    for(int i = 0; i < n; i++)
    {
        if(!v[i])
        {
            answer++;
            dfs(computers, v, n, i);
        }
    }
    return answer;
}