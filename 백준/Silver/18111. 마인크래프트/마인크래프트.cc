// Silver 2. Minecraft

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, B;
    vector<vector<int>> land(500, vector<int>(500, 0));

    cin >> N >> M >> B;

    int min = 257;
    int max = 0;

    int val = pow(2, 31)-1;
    int res = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> land[i][j];

            if (min > land[i][j]) min = land[i][j];
            if (max < land[i][j]) max = land[i][j];
        }
    }

    for (int h = min; h <= max; h++)
    {
        int start = 0;
        int end = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (land[i][j] >= h) end += land[i][j] - h;
                else start += h - land[i][j];
            }
        }

        if (start > end + B) continue;

        int cnt = start + end * 2;

        if (cnt <= val)
        {
            val = cnt;
            res = h;
        }
    }
    
    cout << val << ' ' << res;
}