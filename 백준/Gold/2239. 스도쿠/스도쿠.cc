#include <iostream>

using namespace std;

int board[9][9];

bool is_valid(int r, int c, int num)
{
    // 행과 열 중복 확인
    for (int i = 0; i < 9; i++)
        if (board[r][i] == num || board[i][c] == num)
            return 0;
    
    // 3*3 격자 내 중복 확인
    int cur_r = r/3 * 3;
    int cur_c = c/3 * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[cur_r+i][cur_c+j] == num)
                return 0;

    return 1;
}

bool settings()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (!board[i][j])
            {
                for (int k = 1; k <= 9; k++)
                    if (is_valid(i, j, k))
                    {
                        board[i][j] = k;
                        if (settings())
                            return 1;
                        board[i][j] = 0;
                    }
                // 현재 진행 상태에서는 해를 찾을 수 없는 경우
                return 0;
            }
    // 모든 빈 칸이 채워진 경우
    return 1;
}

void find_answer()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j];

        cout << '\n';
    }
}

void init()
{
    string str;
    for (int i = 0; i < 9; i++)
    {
        cin >> str;
        for (int j = 0; j < 9; j++)
            board[i][j] = str[j]-48;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    if (settings())
        find_answer();
}