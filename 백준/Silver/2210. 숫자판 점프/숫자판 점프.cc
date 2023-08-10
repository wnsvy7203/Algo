// 8ms

#include <iostream>
#include <set>

using namespace std;

int x, y;
char board[5][5];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool visited[5][5];

set<string> s;

void dfs(int r, int c, string digits, int depth)
{
    if (depth == 6)
    {
        s.insert(digits);
        return;
    }

    for (int d = 0; d < 4; d++)
    {
        int nr = r + dr[d];
        int nc = c + dc[d];

        if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)
            continue;
        
        dfs(nr, nc, digits+board[nr][nc], depth+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];
    
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            string empty = "";
            empty += board[i][j];
            dfs(i, j, empty, 1);
        }

    cout << s.size();
}