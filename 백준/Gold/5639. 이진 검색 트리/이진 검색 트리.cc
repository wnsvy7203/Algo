#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> pre;

void post(int s, int e)
{
    if (s > e)
        return;
    
    int m = e+1;

    for (int i = s+1; i < e+1; i++)
        if (pre[s] < pre[i])
        {
            m = i;
            break;
        }
    
    post(s+1, m-1);
    post(m, e);
    cout << pre[s] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> n)
        pre.push_back(n);
    
    post(0, pre.size()-1);
}