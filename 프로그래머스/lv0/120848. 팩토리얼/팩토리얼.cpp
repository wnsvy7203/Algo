#include <string>
#include <vector>

using namespace std;

int factorial(int i){    
    if(i == 1)
        return 1;
    
    return i * factorial(i-1);
}

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n ; i++)
    {
        answer = factorial(i);
        
        if (answer >= n)
        {
            if (answer == n)
                return i;
            return i-1;
        }
    }
}