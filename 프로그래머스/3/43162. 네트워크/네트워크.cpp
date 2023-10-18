#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[200];
bool visited[200];

void dfs(int s)
{
    stack<int> stk;
    stk.push(s);
    visited[s] = 1;
    
    while (!stk.empty())
    {
        int t = stk.top();
        stk.pop();
        
        for (int a : graph[t])
        {
            if (!visited[a])
            {
                visited[a] = 1;
                stk.push(a);
            }
        }
    }
    
    
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && computers[i][j])
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
    
    int answer = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            answer++;
            dfs(i);
        }
            
    return answer;
}