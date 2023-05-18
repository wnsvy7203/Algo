#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    
    cin >> N;
    
    vector<int> A;
    vector<int> B;
    
    for (int i = 0; i < N; i++)
    {
        int a, b;
        
        cin >> a >> b;
        
        A.push_back(a);
        B.push_back(b);
    }
    
    int l = *max_element(A.begin(), A.end()) - *min_element(A.begin(), A.end());
    int h = *max_element(B.begin(), B.end()) - *min_element(B.begin(), B.end());
    
    cout << l * h;
}