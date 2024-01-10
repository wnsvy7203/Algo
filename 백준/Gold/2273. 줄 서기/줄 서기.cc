// 32ms

#include <iostream>

using namespace std;

int N, M;
bool graph[257][257];

void input()
{
    cin >> N >> M;
    while (M--)
    {
        int A, B;
        cin >> A >> B;
        graph[A][B] = 1;
    }
}

void floyd()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
}

void find_answer()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (graph[i][j] && graph[j][i])
            {
                cout << -1;
                return;
            }

    for (int i = 1; i <= N; i++)
    {
        int small = N;
        int tall = 1;

        for (int j = 1; j <= N; j++)
        {
            if (graph[i][j])
                small--;
            else if (graph[j][i])
                tall++;
        }

        cout << tall << ' ' << small << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    floyd();
    find_answer();
}