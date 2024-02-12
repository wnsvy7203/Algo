#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int come[1000001], go[1000001];
vector<int> answer(4, 0);

// 도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프의 수의 합은 2 이상이므로, 루트 노드는 2 이상의 진출 간선과, 0의 진입 간선을 가진다.
void find_root()
{
    for (int i = 1; i <= N; i++)
        if (go[i] >= 2 && !come[i])
        {
            answer[0] = i;
            return;
        }
}

// 막대 모양 그래프는 모든 정점에서의 진출 간선의 개수가 1, 진입 간선이 1이다. 다만, 마지막 정점에서는 진출 노드가 없으므로, 진출 노드가 없는 정점을 찾으면 해당 그래프가 막대 그래프이다.
bool is_stick(int node)
{
    return go[node] == 0;
}

// 8자 모양 그래프는 크기가 동일한 2개의 도넛 모양 그래프에서 정점을 하나씩 골라 결합시킨 형태이다. 따라서, 진출 간선이 2, 진입 간선도 2가 되는 정점을 찾아야 한다. 다만, 8자 모양 그래프를 구성하는 특정 정점이 루트 노드에서의 진출 간선과 이어져 있다면 진입 간선의 개수는 3이 될 수도 있다.
bool is_eight(int node)
{
    return come[node] >= 2 && go[node] == 2;
}

// 도넛 모양 그래프는 좀 애매한 것이, 아무 정점에서 출발해도 결국은 다른 정점들을 한 번씩 방문한 이후 원래 출발했던 정점으로 돌아오게 된다. 즉, 모든 정점의 진출 간선이 1, 진입 간선이 1이기 때문에 막대 모양 그래프나 8자 모양 그래프와 달리 특정 노드의 특징을 찾아 개수를 셀 수 없다. 따라서 도넛 모양 그래프, 8자 모양 그래프의 개수를 구해 전체에서 빼 주면 되겠다.
vector<int> solution(vector<vector<int>> edges)
{
    for (vector<int> v : edges)
    {
        go[v[0]]++;
        come[v[1]]++;
        N = max({N, v[0], v[1]});
    }
    
    find_root();
    
    for (int i = 1; i <= N; i++)
    {
        if (is_stick(i))
            answer[2]++;
        else if (is_eight(i))
            answer[3]++;
    }
    
    answer[1] = go[answer[0]] - answer[2] - answer[3];
    
    return answer;
}