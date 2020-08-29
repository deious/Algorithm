#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int a = 0, b = people.size();
    
    sort(people.rbegin(), people.rend());
    
    while(a < b)
    {
        if(b == 1)
        {
            return answer = 1;
        }
        
        if(people[a] + people[b - 1] <= limit)
        {
            answer++;
            a++;
            b--;
        }
        else
        {
            answer++;
            a++;
        }
    }
    
    return answer;
}