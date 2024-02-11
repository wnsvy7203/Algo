#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 각 방향 디렉션
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int n, m;
int board[500][500];

// 방문 배열
bool visited[500][500];

// 방문 column 배열
bool visited_col[500];
int ans[500];

int res = 0;
void dfs(int r, int c)
{
    for (int d = 0; d < 4; d++)
    {
        int nr = r + dr[d];
        int nc = c + dc[d];
        
        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            continue;
        
        if (!visited[nr][nc] && board[nr][nc])
        {
            visited[nr][nc] = 1;
            visited_col[nc] = 1;
            res++;
            dfs(nr, nc);
        }
    }
}

int solution(vector<vector<int>> land)
{    
    // 순회에 필요한 n, m 갱신
    n = land.size();
    m = land[0].size();
    
    // dfs를 위해 전역 변수 board 배열 초기화
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            board[i][j] = land[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[j][i] && board[j][i])
            {
                visited[j][i] = 1;
                visited_col[i] = 1;
                res++;
                
                dfs(j, i);
                
                for (int k = 0; k < m; k++)
                    if (visited_col[k])
                    {
                        visited_col[k] = 0;
                        ans[k] += res;
                    }
                
                res = 0;
            }
        }
    }

    return *max_element(ans, ans+m);
}