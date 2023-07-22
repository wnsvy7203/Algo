#include <iostream>
#include <stack>
#include <numeric>

using namespace std;

int n, s;
int stones[100001];
int visited[100001];

stack<int> stk;

void dfs(int x)
{
    stk.push(x);

    while (!stk.empty())
    {
        int t = stk.top();
        stk.pop();
        
        visited[t] = 1;

        int step = stones[t];

        if (t-step > 0 && !visited[t-step])
            stk.push(t-step);

        if (t+step <= 100000 && !visited[t+step])
            stk.push(t+step);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> stones[i];
    
    cin >> s;

    dfs(s);

    cout << accumulate(visited+1, visited+n+1, 0);
}