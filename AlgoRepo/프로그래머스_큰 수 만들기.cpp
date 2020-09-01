#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int nLen = number.size();
    int len = nLen - k;
    stack<char> s;
    
    for(int i = 0; i < nLen; i++)
    {
        char c = number[i];
        
        while(!s.empty() && k > 0)
        {
            char temp = s.top();
            
            if(temp < c)
            {
                s.pop();
                k--;
            }
            else
            {
                break;
            }
        } 
        s.push(c);
    }
    
    while(s.size() != len)
    {
        s.pop();
    }

    
    while(!s.empty())
    {
        answer += s.top();
        s.pop();
    }
    
    reverse(answer.begin(), answer.end()); 
    
    return answer;
}