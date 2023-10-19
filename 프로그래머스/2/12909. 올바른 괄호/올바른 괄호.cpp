#include<string>
#include <iostream>
#include <stack>

using namespace std;

stack<char> stk;

bool solution(string s)
{
    bool answer = true;
    for (char c : s)
        if (c == '(')
            stk.push(c);
        else if (stk.empty())
            answer = 0;
        else if (stk.top() == '(')
            stk.pop();
        else
            answer = 0;
    

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    if (!stk.empty())
        answer = 0;

    return answer;
}