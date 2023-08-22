//

#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int N, M, X;
vector<int> graph[MAX];
bool visited[MAX];

int ans = 0;
void dfs(int r)
{
    for (int x : graph[r])
        if (!visited[x])
        {
            ans++;
            visited[x] = 1;
            dfs(x);
        }
}

int main()
{
    cin >> N >> M;
    int A, B;
    while (M--)
    {
        cin >> A >> B;
        graph[B].push_back(A);
    }
    cin >> X;

    visited[X] = 1;
    dfs(X);

    cout << ans;
}