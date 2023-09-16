#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while (a)
    {
        int tmp = a;
        a = b % a;
        b = tmp;
    }
    
    return b;
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    int ans1 = numer1 * denom2 + numer2 * denom1;
    int ans2 = denom1 * denom2;
    
    int div = ans1 > ans2 ? gcd(ans2, ans1) : gcd(ans1, ans2);        
    
    vector<int> answer;
    
    

    answer.push_back(ans1 / div);
    answer.push_back(ans2 / div);
    
    return answer;
}