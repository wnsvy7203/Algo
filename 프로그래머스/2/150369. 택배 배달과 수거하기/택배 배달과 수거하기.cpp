#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    // d: delivery, p: pickup
    int d = n-1, p = n-1;
    while (d >= 0 || p >= 0)
    {
        while (d >= 0 && !deliveries[d])
            d--;
        while (p >= 0 && !pickups[p])
            p--;

        n = max(d, p);
        answer += (n+1) * 2;
        
        // 현재 트럭에 담고 있는 d, p
        int now_d = 0, now_p = 0;
                
        for (int i = d; i >= 0; i--)
        {
            if (!deliveries[i])
                continue;

            if (now_d + deliveries[i] >= cap)
            {
                deliveries[i] -= (cap - now_d);
                now_d += (cap - now_d);
            }
            else
            {
                now_d += deliveries[i];
                deliveries[i] = 0;
            }

            if (now_d == cap)
                break;
        }
        
        for (int i = p; i >= 0; i--)
        {
            if (!pickups[i])
                continue;

            if (now_p + pickups[i] >= cap)
            {
                pickups[i] -= (cap - now_p);
                now_p += (cap - now_p);
            }
            else
            {
                now_p += pickups[i];
                pickups[i] = 0;
            }

            if (now_p == cap)
                break;
        }
    }
    
    return answer;
}