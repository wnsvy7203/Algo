#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!(n % i))
            cnt++;
    
    if (cnt % 2)
        return 1;
    else
        return 2;
}