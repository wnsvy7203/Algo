#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int MAX1 = 0;
    int MAX2 = 0;
    
    for (vector<int> v : sizes)
    {
        MAX1 = max(MAX1, max(v[0], v[1]));
        MAX2 = max(MAX2, min(v[0], v[1]));
    }
    
    return MAX1 * MAX2;
}