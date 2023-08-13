// 

#include <iostream>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

string MS;
int time;
bool visited[3660];

queue<tuple<int, bool, int>> que;

void bfs()
{
    que.push({0, 0, 0});
    visited[0] = 1;

    while (!que.empty())
    {
        int f = get<0>(que.front());
        bool flag = get<1>(que.front());
        int cnt = get<2>(que.front());        

        que.pop();

        if (f == time)
        {
            if (flag)
                cout << cnt;
            else
                cout << cnt+1;
            return;
        }

        if (f+10 <= time && !visited[f+10])
        {
            que.push({f+10, flag, cnt+1});
            visited[f+10] = 1;
        }

        if (f+30 <= time && !visited[f+30])
        {
            que.push({f+30, 1, cnt+1});
            visited[f+30] = 1;
        }

        if (f+60 <= time && !visited[f+60])
        {
            que.push({f+60, flag, cnt+1});
            visited[f+60] = 1;
        }

        if (f+600 <= time && !visited[f+600])
        {
            que.push({f+600, flag, cnt+1});
            visited[f+600] = 1;
        }
    }
}

int main()
{
    cin >> MS;

    time = stoi(MS.substr(0, 2))*60 + stoi(MS.substr(3, 2));

    bfs();
}