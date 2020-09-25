#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1000;
    int len = s.size();
    int tLen = len / 2;
    
    if(len == 1) return 1;
    
    for(int i = 1; i <= tLen; i++)
    {
        string s1 = "";
        string str = s.substr(0, i);
        
        int count = 1;
        
        for(int j = i; j <= len; j += i)
        {
            if(str == s.substr(j, i))
            {
                count++;
            }
            else
            {
                if(count == 1)
                {
                    s1 += str;
                }
                else
                {
                    s1 += to_string(count) + str;
                }
                
                str = s.substr(j, i);
                count = 1;
            }
        }
        
        if(len % i != 0)
        {
            s1 += s.substr(len - len % i, len % i);
        }
        
        if(answer > s1.size())
        {
            answer = s1.size();
        }
    }
    
    return answer;
}