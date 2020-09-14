#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size();
    int index = len / 2;
    
    if(len % 2 == 0)
    {
        answer += s[index -1];
        answer += s[index];
    }
    else
    {
        answer += s[index];
    }
    
    return answer;
}