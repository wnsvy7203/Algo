// Silver 1. Nearest Three People's Psychological Distance
// 104ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int distance(string a, string b)
{
    int dist = 0;
    for (int i = 0; i < 4; i++)
        if (a[i] != b[i])
            dist++;
    
    return dist;
}

int T;
string type[33];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--)
    {
        int N;

        cin >> N;

        for (int i = 0; i < N; i++)
        {
            string mbti;
            cin >> mbti;

            if (N <= 32)
                type[i] = mbti;                
        }
        
        if (N > 32)
            cout << 0 << '\n';
        else
        {
            int minV = 1000;
        
            bool v[N] = {0, };
            for (int i = N-1; i >= N-3; i--)
                v[i] = 1;
            
            do
            {
                vector<int> idx;
                for (int i = 0; i < N; i++)
                    if (v[i]) idx.push_back(i);

                minV = min(minV, distance(type[idx[0]], type[idx[1]]) + distance(type[idx[1]], type[idx[2]]) + distance(type[idx[2]], type[idx[0]]));

            } while (next_permutation(v, v+N));

            cout << minV << '\n';
        }
    }
}