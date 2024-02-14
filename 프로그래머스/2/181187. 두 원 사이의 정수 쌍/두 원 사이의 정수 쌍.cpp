#include <string>
#include <vector>
#include <cmath>

using namespace std;

// idea 1: 중심이 원점이라고 했기 때문에 각 사분면마다 해당되는 점의 개수를 구해서 곱하기 4 하면 되지 않을까 생각했다. x축, y축 상의 점들 역시 r2-r1+1 * 4 해서 구할 수 있다.

// idea 2: 첫 번째 아이디어보다는 반지름이 r2인 원에 속하는 좌표의 개수에서 반지름이 r1인 원에 속하는 좌표의 개수를 빼 주면 더 쉽게 구할 수 있지 않을까?

long long ans;

long long solution(int r1, int r2) {    
    for (long long i = 1; i <= r2; i++)
    {
        long long min_y = sqrt((long long)r1 * r1 - i * i);
        if (i * i + min_y * min_y < (long long)r1 * r1)
            min_y++;

        long long max_y = sqrt((long long)r2 * r2 - i * i);
        ans += (max_y - min_y + 1);
    }
    
    ans *= 4;
    return ans;
}