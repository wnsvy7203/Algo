// 플로이드-워셜
// 모든 정점에서 모든 정점으로의 최단 경로를 한 번에 구한다.
// 모든 쌍을 표현하는 이차원 배열을 선언하고 dp로 각각의 원소를 업데이트 해나간다.
// 거쳐가는 정점을 기준으로 알고리즘을 수행한다.
// i -> j 로 가는데 해당 정점을 경유해서 가는 것이 더 빠르다면 그 정점을 거쳐서 가게끔 업데이트한다.

// 시간 복잡도: O(V^3)

#include <iostream>
#include <vector>

#define INF 100

using namespace std;

int N;
int member[51][51];

void input()
{
    cin >> N;
    fill_n(&member[0][0], 51 * 51, INF);
    for (int i = 1; i <= N; i++)
        member[i][i] = 0;
    
    while (1)
    {
        int u, v;
        cin >> u >> v;
        
        if (u == -1 && v == -1)
            break;
        
        member[u][v] = 1;
        member[v][u] = 1;
    }
}

void floyd()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                member[i][j] = min(member[i][j], member[i][k] + member[k][j]);
}

int res = INF;
vector<int> nom;
void find_answer()
{
    for (int i = 1; i <= N; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= N; j++)
            tmp = max(tmp, member[i][j]);
        
        res = min(res, tmp);
    }
    cout << res << ' ';

    for (int i = 1; i <= N; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= N; j++)
            tmp = max(tmp, member[i][j]);
        
        if (tmp == res)
            nom.push_back(i);
    }
    cout << nom.size() << '\n';
    for (int n : nom)
        cout << n << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    floyd();
    find_answer();
}