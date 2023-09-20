#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[1001];
int solution(vector<int> array, int n) {
    for (int num : array)
        cnt[num]++;
    return cnt[n];
}