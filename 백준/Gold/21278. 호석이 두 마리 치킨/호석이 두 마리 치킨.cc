#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

#define INF 1e8

using namespace std;

int N, M;
int graph[101][101];
void input()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;

            graph[i][j] = INF;
        }

    while (M--)
    {
        int A, B;
        cin >> A >> B;
        graph[A][B] = 1;
        graph[B][A] = 1;
    }
}

void floyd()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

vector<int> v;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
void find_answer()
{
    for (int i = 0; i < N-2; i++)
        v.push_back(0);
    for (int i = 0; i < 2; i++)
        v.push_back(1);
    
    do
    {
        int first = 0;
        int second = 0;
        for (int i = 0; i < N; i++)
        {
            if (v[i])
            {
                if (first)
                    second = i+1;
                else
                    first = i+1;
            }
        }

        int res = 0;
        for (int i = 1; i <= N; i++)
            res += min(graph[i][first], graph[i][second]);

        pq.push({res*2, first, second});
    } while (next_permutation(v.begin(), v.end()));
    
    cout << get<1>(pq.top()) << ' ' << get<2>(pq.top()) << ' ' << get<0>(pq.top());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    floyd();
    find_answer();
}