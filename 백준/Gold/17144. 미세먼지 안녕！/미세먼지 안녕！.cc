#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
int A[50][50];  // 미세먼지
int B[50][50];  // 더하고 빼는 데 써
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<int> con;
int ans;

void spread()
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            int cnt = 0;
            int add = A[i][j] / 5;

            if (A[i][j] == 0 || A[i][j] == -1)
                continue;
            
            for (int d = 0; d < 4; d++)
            {
                int nr = i + dr[d];
                int nc = j + dc[d];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                    continue;
                if (A[nr][nc] == -1)
                    continue;
                
                B[nr][nc] += add;
                cnt++;
            }
            B[i][j] -= (cnt * add);
        }
        
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            A[i][j] += B[i][j];
            B[i][j] = 0;
        }
}

void clean()
{
    // 위 (왼 -> 위 -> 오 -> 밑)
    for (int i = con[0]-1; i > 0; i--)
        A[i][0] = A[i-1][0];
    for (int i = 0; i < C-1; i++)
        A[0][i] = A[0][i+1];
    for (int i = 1; i <= con[0]; i++)
        A[i-1][C-1] = A[i][C-1];
    for (int i = C-1; i > 1; i--)
        A[con[0]][i] = A[con[0]][i-1];
    A[con[0]][1] = 0;

    // 아래 (왼 -> 위 -> 오 -> 밑)
    for (int i = con[1]+1; i < R-1; i++)
        A[i][0] = A[i+1][0];
    for (int i = 0; i < C-1; i++)
        A[R-1][i] = A[R-1][i+1];
    for (int i = R-1; i >= con[1]; i--)
        A[i][C-1] = A[i-1][C-1];
    for (int i = C-1; i > 1; i--)
        A[con[1]][i] = A[con[1]][i-1];
    A[con[1]][1] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == -1)
                con.push_back(i);
            else
                ans += A[i][j];
        }

    while (T--)
    {
        spread();
        clean();
    }
    
    int ans = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (A[i][j] != -1)
                ans += A[i][j];
    cout << ans;
}