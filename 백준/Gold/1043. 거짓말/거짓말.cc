#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, K;        // N: 사람의 수, M: 파티의 수, K: 진실을 아는 사람의 수
bool known[51];     // 진실을 아는지 모르는지 확인
vector<int> party[51], graph[51];
vector<bool> visited;

queue<int> que;
void bfs(int n)
{
    que.push(n);

    while(!que.empty())
    {
        int f = que.front();
        que.pop();

        for (int num : graph[f])
            if (!known[num])
            {
                known[num] = 1;
                que.push(num);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    while (K--)
    {
        int num;
        cin >> num;
        known[num] = true;
    }

    for (int i = 1; i <= M; i++)
    {
        int p;
        cin >> p;
        while (p--)
        {
            int par;
            cin >> par;

            party[i].push_back(par);
        }
    }

    for (int i = 1; i <= M; i++)
    {
        visited.clear();
        int len = party[i].size();
        if (len < 2)
            continue;
        
        for (int j = 0; j < len-2; j++)
            visited.push_back(0);
        for (int j = 0; j < 2; j++)
            visited.push_back(1);

        do
        {
            int one = 0;
            int two = 0;
            for (int j = 0; j < len; j++)
            {
                if (visited[j])
                {
                    if (!one)
                        one = party[i][j];
                    else if (!two)
                        two = party[i][j];
                }
            }

            if (one && two)
            {
                graph[one].push_back(two);
                graph[two].push_back(one);
            }

        } while (next_permutation(visited.begin(), visited.end()));
    }
    
    for (int i = 1; i < 51; i++)
        if (known[i])
            bfs(i);
    
    int ans = 0;
    for (int i = 1; i <= M; i++)
    {
        bool flag = 1;
        for (int p : party[i])
        {
            if (known[p])
                flag = 0;
        }

        if (flag)
            ans++;
    }

    cout << ans;
}