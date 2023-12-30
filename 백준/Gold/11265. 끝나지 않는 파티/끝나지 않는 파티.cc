#include <iostream>

#define INF 2e9

using namespace std;

int N, M;
int board[501][501];

void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
}

void floyd()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void find_answer()
{
    while (M--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        if (board[A][B] <= C)
            cout << "Enjoy other party\n";
        else
            cout << "Stay here\n";
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