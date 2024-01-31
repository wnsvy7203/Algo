// 20ms

#include <iostream>

#define MAX 1001

using namespace std;

int N, M;
int par[MAX*MAX];
char board[MAX][MAX];

int find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

void union_sets(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x > y)
        swap(x, y);

    par[y] = x;
}

void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        
        for (int j = 0; j < M; j++)
            board[i][j] = str[j];
    }

    for (int i = 1; i < N*M; i++)
        par[i] = i;
}

int ans;
void find_answer()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            int comp1 = i * M + j;
            int comp2 = N*M;
            switch (board[i][j])
            {
                case 'U':
                    comp2 = comp1 - M;
                    break;
                case 'D':
                    comp2 = comp1 + M;
                    break;
                case 'L':
                    comp2 = comp1 - 1;
                    break;
                case 'R':
                    comp2 = comp1 + 1;
                    break;
            }

            if (comp2 < 0 || comp2 >= N*M)
                continue;

            union_sets(comp1, comp2);
        }
    
    for (int i = 0; i < N*M; i++)
        if (par[i] == i)
            ans++;

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    find_answer();
}