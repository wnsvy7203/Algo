#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int board[100001];
bool check[1000001];
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
        check[board[i]] = 1;
    }
}

int scores[1000001];
void perm()
{
    for (int i = 0; i < N; i++)
    {
        int start = board[i];
        for (int j = start*2; j < 1000001; j += start)
            if (check[j])
            {
                scores[start]++;
                scores[j]--;
            }
    }
}

void find_answer()
{
    for (int i = 0; i < N; i++)
        cout << scores[board[i]] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    perm();
    find_answer();
}