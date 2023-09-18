#include <string>
#include <vector>

using namespace std;

int lcm(int a, int b)
{
    int x = a, y = b;
    while (x)
    {
        int tmp = x;
        x = y % x;
        y = tmp;
    }
    
    return a * b / y;
}
    

    

int solution(int n) {
    if (n > 6)
        return lcm(6, n) / 6;
    else if (n < 6)
        return lcm(n, 6) / 6;
    else
        return 1;
}