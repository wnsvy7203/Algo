#include <iostream>

using namespace std;

int N, M;
int board[2001];
bool ans[2001][2001];

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> board[i];
}

void dp()
{
    // 길이가 1인 수열은 반드시 펠린드롬
    for (int i = 1; i <= N; i++)
        ans[i][i] = 1;
    
    // 길이가 2인 수열 중 2개의 원소가 같으면 펠린드롬
    for (int i = 1; i < N; i++)
        if (board[i] == board[i+1])
            ans[i][i+1] = 1;
    
    // 길이가 3인 것부터는 dp로 해결
    for (int end = 3; end <= N; end++)
        for (int start = end-2; start > 0; start--)
            if (board[start] == board[end] && ans[start+1][end-1])
                ans[start][end] = 1;
}

void find_answer()
{
    cin >> M;
    while (M--)
    {
        int S, E;
        cin >> S >> E;
        cout << ans[S][E] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    dp();
    find_answer();
}