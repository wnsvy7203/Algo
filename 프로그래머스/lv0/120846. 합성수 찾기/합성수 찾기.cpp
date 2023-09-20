#include <string>
#include <vector>

using namespace std;

bool cnt[101];

void tera()
{
    for (int i = 2; i < 101; i++)
        if (!cnt[i])
            for (int j = i*2; j < 101; j += i)
                cnt[j] = 1;
            
}

int solution(int n) {
    tera();
    int answer = 0;
    for (int i = 1; i <= n; i++)
        if (cnt[i])
            answer++;
    return answer;
}