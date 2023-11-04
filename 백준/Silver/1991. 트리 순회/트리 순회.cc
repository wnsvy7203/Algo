#include <iostream>
#include <vector>

using namespace std;

int N;
char p, c1, c2;
int graph[26][2];

void pre(int n)
{
    cout << (char)(n+65);
    if (graph[n][0])
        pre(graph[n][0]);
    if (graph[n][1])
        pre(graph[n][1]);
}

void in(int n)
{
    if (graph[n][0])
        in(graph[n][0]);
    cout << (char)(n+65);
    if (graph[n][1])
        in(graph[n][1]);
}

void post(int n)
{
    if (graph[n][0])
        post(graph[n][0]);
    if (graph[n][1])
        post(graph[n][1]);
    cout << (char)(n+65);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> p >> c1 >> c2;
        p -= 65;

        if (c1 != '.')
            graph[p][0] = c1-65;
        
        if (c2 != '.')
            graph[p][1] = c2-65;
    }

    pre(0);
    cout << '\n';
    in(0);
    cout << '\n';
    post(0);
}