#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int len = routes.size();
    
    sort(routes.begin(), routes.end());
    
    int cPos = routes[0][1];
    
    for(int i = 1; i < len; i++)
    {
        if(cPos >= routes[i][0]) 
        {
            cPos = min(cPos, routes[i][1]);
        }
        else
        {
            cPos = routes[i][1];
            answer++;
        }
    }
        
    return answer;
}