#include <iostream>
#include <vector>
#include <tuple>

#define INF 1e9

using namespace std;

int N, T, M;
vector<tuple<bool, int, int>> v;
int graph[1001][1001];

int dist(tuple<bool, int, int> a, tuple<bool, int, int> b)
{
    return abs(get<1>(a) - get<1>(b)) + abs(get<2>(a) - get<2>(b));
}

void floyd()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            graph[i][j] = INF;
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            graph[i][j] = dist(v[i], v[j]);
            
            if (get<0>(v[i]) && get<0>(v[j]))
                graph[i][j] = min(graph[i][j], T);
        }
    
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        bool s;
        int x, y;
        cin >> s >> x >> y;
        v.push_back({s, x, y});
    }

    floyd();

    cin >> M;
    while (M--)
    {
        int A, B;
        cin >> A >> B;
        cout << graph[A-1][B-1] << '\n';
    }
}