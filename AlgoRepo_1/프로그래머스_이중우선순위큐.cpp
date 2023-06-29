#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    deque<int> dq;
    
    int len = operations.size();
    
    for(int i =0; i < len; i++)
    {
        char c = operations[i][0];
        int num = stoi(operations[i].substr(2));
        
        if(c == 'I')
        {
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        }
        else
        {
            if(num == -1 && !dq.empty())
            {
                dq.pop_front();
            }
            else if(num == 1 && !dq.empty())
            {
                dq.pop_back();
            }
        }
    }
    
    if(dq.empty())
    {
        answer[0] = 0;
        answer[1] = 0;
    }
    else
    {
        answer[0] = dq.back();
        answer[1] = dq.front();
    }
    
    return answer;
}