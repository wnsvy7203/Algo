#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
vector<int> perm;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        v.push_back(i);
    
    for (int i = 0; i < M; i++)
        perm.push_back(1);

    for (int i = 0; i < N-M; i++)
        perm.push_back(0);
    
    
    do
    {
        for (int i = 0; i < N; i++)
            if (perm[i])
                cout << v[i] << ' ';
        cout << '\n';
    } while (prev_permutation(perm.begin(), perm.end()));
    
}