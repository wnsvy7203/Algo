#include <iostream>

using namespace std;

int N;
bool graph[58][58];

void input()
{
    cin >> N;
    cin.ignore();
    while (N--)
    {
        string proposition;
        getline(cin, proposition);
        int start = proposition[0];
        int end = proposition[5];

        start -= 'A';
        end -= 'A';

        if (start == end)
            continue;
        
        graph[start][end] = 1;
    }
}

void floyd()
{
    for (int k = 0; k < 58; k++)
        for (int i = 0; i < 58; i++)
            for (int j = 0; j < 58; j++)
            {
                if (graph[i][j] || i == j)
                    continue;

                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
            }
}

void find_answer()
{
    int X = 0;
    for (int i = 0; i < 58; i++)
        for (int j = 0; j < 58; j++)
        {
            if (i == j)
                continue;

            if (graph[i][j])
                X++;
        }
    cout << X << '\n';

    for (int i = 0; i < 58; i++)
        for (int j = 0; j < 58; j++)
            if (graph[i][j])
                cout << (char)(i + 'A') << " => " << (char)(j + 'A') << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    floyd();
    find_answer();
}