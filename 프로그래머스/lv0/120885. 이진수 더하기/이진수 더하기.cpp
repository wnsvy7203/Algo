#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string cal(string a, string b)
{
    string answer = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    bool flag = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '0' && b[i] == '0')
        {
            if (flag)
                answer += '1';
            else
                answer += '0';
            
            flag = 0;
        }
        else if (a[i] == '1' && b[i] == '1')
        {
            if (flag)
                answer += '1';
            else
            {
                answer += '0';
                flag = 1;
            }
        }
        else
            if (flag)
                answer += '0';
            else
                answer += '1';
    }
    
    for (int i = a.size(); i < b.size(); i++)
    {
        if (b[i] == '0')
        {
            if (flag)
                answer += '1';
            else
                answer += '0';
            
            flag = 0;
        }
        else
        {
            if (flag)
                answer += '0';
            else
                answer += '1';
        }
    }
    
    if (flag)
        answer += '1';
    
    reverse(answer.begin(), answer.end());
    return answer;
}

string solution(string bin1, string bin2) {
    if (bin1.size() < bin2.size())
        return cal(bin1, bin2);
    else
        return cal(bin2, bin1);
}