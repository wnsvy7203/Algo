// 36ms

#include <iostream>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

int P;
string goal;

void bfs()
{
    queue<pair<string, int>> que;
    set<string> s;
    string board = ".........";
    que.push({board, 0});
    s.insert(board);

    vector<int> link[9] = {
        {0, 1, 3},
        {0, 1, 2, 4},
        {1, 2, 5},
        {0, 3, 4, 6},
        {1, 3, 4, 5, 7},
        {2, 4, 5, 8},
        {3, 6, 7},
        {4, 6, 7, 8},
        {5, 7, 8},
    };

    while (!que.empty())
    {
        string f = que.front().first;
        int cnt = que.front().second;
        que.pop();

        if (f == goal)
        {
            cout << cnt;
            break;
        }

        for (int i = 0; i < 9; i++)
        {
            string tmp = f;
            for (int j = 0; j < link[i].size(); j++)
            {
                if (tmp[link[i][j]] == '.')
                    tmp[link[i][j]] = '*';
                else
                    tmp[link[i][j]] = '.';
            }
            
            if (!s.count(tmp))
            {
                s.insert(tmp);
                que.push({tmp, cnt+1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> P;

    while (P--)
    {
        goal = "";

        for (int i = 0; i < 3; i++)
        {
            string str;

            cin >> str;

            goal += str;
        }

        bfs();

        cout << '\n';
    }
}