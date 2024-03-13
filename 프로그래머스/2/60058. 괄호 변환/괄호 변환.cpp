#include <string>
#include <algorithm>

using namespace std;

bool flag(string str)
{
    int cnt = 0;
    for (char c : str)
    {
        if (c == '(')
            cnt++;
        else
            cnt--;
        
        if (!cnt)
            return 1;
        else if (cnt == -1)
            return 0;
    }
}

string recur(string str)
{
    if (str == "")
        return str;
    
    int cnt = 0, idx = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            cnt++;
        else
            cnt--;
        
        if (!cnt)
        {
            idx = i;
            break;
        }       
    }
    
    string u = str.substr(0, idx+1);
    string v = str.substr(idx+1);
    
    if (flag(u))
        return u + recur(v);
    else
    {
        string answer = "";
        answer += '(';
        answer += recur(v);
        answer += ')';
        
        u = u.substr(1, u.size()-2);
        for (int i = 0; i < u.size(); i++)
            if (u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        
        answer += u;
        return answer;
    }
}

string solution(string p) {    
    return recur(p);
}