#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    n /= 2;
    
    int sum = 0;
    for (int i = n; i > 0; i--)
        sum += i * 2;
    
    return sum;
}