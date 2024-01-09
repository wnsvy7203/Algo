#include <iostream>

using namespace std;

int n, k, s;
bool graph[401][401];

void input()
{
    cin >> n >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        graph[b][a] = 1;
    }
}

void floyd()
{
    for (int z = 1; z <= n; z++)
        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= n; y++)
            {
                if (x == y)
                    continue;

                if (graph[x][z] && graph[z][y])
                    graph[x][y] = 1;
            }
}

void find_answer()
{
    cin >> s;
    while (s--)
    {
        int a, b;
        cin >> a >> b;

        if (graph[a][b])
            cout << "1\n";
        else if (graph[b][a])
            cout << "-1\n";
        else
            cout << "0\n";
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