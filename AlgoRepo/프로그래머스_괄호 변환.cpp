#include <string>
#include <vector>

using namespace std;

bool checkCorrect(string s)
{
    int count = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') count++;
        else count--;
        
        if(count < 0) return false;
    }
    
    return true;
}

string checkStr(string s)
{
    if(s == "") return s;
    string u, v;   
    int lCount = 0, rCount = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(') lCount++;
        else rCount++;
        
        if(lCount == rCount)
        {
            u = s.substr(0, i + 1);
            v = s.substr(i + 1);
            break;
        }
    }
    
    if(checkCorrect(u)) return u + checkStr(v);
    else
    {
        string temp = "";
        temp += '(' + checkStr(v) + ')';
        u = u.substr(1, u.size() - 2);
        
        for(int i = 0; i < u.size(); i++)
        {
            if(u[i] == '(') temp += ')';
            else temp += '(';
        }
        
        return temp;
    }
}

string solution(string p) {
    
    return checkStr(p);
}