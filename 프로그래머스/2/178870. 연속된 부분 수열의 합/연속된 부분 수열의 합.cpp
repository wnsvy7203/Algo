#include <string>
#include <vector>

using namespace std;

int N, s, e;
vector<int> answer(2, 0);

vector<int> solution(vector<int> sequence, int k) {
    N = sequence.size();
    int MIN = N+1;
    int sum = sequence[0];
    
    while (s <= e && e < N)
    {
        if (sum < k)
        {
            e++;
            sum += sequence[e];
            continue;
        }
        else if (sum == k)
        {
            int len = e - s + 1;
            
            if (MIN > len)
            {
                MIN = len;
                answer[0] = s;
                answer[1] = e;
            }
            else if (MIN == len && s < answer[0])
            {
                answer[0] = s;
                answer[1] = e;
            }
        }
        
        sum -= sequence[s];
        s++;
    }
    
    return answer;
}