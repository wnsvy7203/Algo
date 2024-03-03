#include <iostream>
#include <set>
#include <queue>
#include <map>

using namespace std;

int N, M;
int board[1000][1000], area[1000][1000];
bool visited[1000][1000];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int idx = 0;
map<int, int> m;

int bfs(int i, int j)
{
    queue<pair<int, int>> que;
    que.push({i, j});
    visited[i][j] = 1;
    int cnt = 0;

    while (!que.empty())
    {
        int r = que.front().first;
        int c = que.front().second;
        que.pop();

        area[r][c] = idx;
        cnt++;

        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                continue;

            if (!visited[nr][nc] && !board[nr][nc])
            {
                visited[nr][nc] = 1;
                que.push({nr, nc});
            }
        }
    }
    
    return cnt;
}

void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
            board[i][j] = str[j]-48;
    }
}

void settings()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!visited[i][j] && !board[i][j])
            {
                idx++;
                int res = bfs(i, j);
                
                m[idx] = res % 10;
            }
}

void find_answer()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            set<int> adjacent;
            if (board[i][j])
            {
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + dr[d];
                    int nj = j + dc[d];

                    if (ni < 0 || ni >= N || nj < 0 || nj >= M)
                        continue;
                    
                    if (area[ni][nj])
                        adjacent.insert(area[ni][nj]);
                }

                for (auto it : adjacent)
                {
                    board[i][j] += m[it];
                    board[i][j] %= 10;
                }
                
                cout << board[i][j];
            }
            else
                cout << 0;
        }

        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    settings();
    find_answer();
}