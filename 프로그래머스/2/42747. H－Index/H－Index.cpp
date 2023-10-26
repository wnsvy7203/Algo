#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int len = citations.size();
    for (int h = len; h >= 0; h--)
    {
        int cnt = 0;
        for (int num : citations)
            if (num >= h)
                cnt++;
        
        if (cnt >= h)
            return h;
    }
}