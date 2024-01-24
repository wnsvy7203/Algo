#include <iostream>
#include <vector>

using namespace std;

int num;
vector<int> steps;
int dp[100000][5][5];

void input()
{
    while (cin >> num)
    {
        if (!num)
            break;
        
        steps.push_back(num);
    }
}

int cost(int idx, int next)
{
    if (idx == next)
        return 1;
    else if (idx == 1)
    {
        switch (next)
        {
            case 2:
                return 3;
                break;
            case 4:
                return 3;
                break;
            case 3:
                return 4;
                break;
        }
    }
    else if (idx == 2)
    {
        switch (next)
        {
            case 1:
                return 3;
                break;
            case 3:
                return 3;
                break;
            case 4:
                return 4;
                break;
        }
    }
    else if (idx == 3)
    {
        switch (next)
        {
            case 2:
                return 3;
                break;
            case 4:
                return 3;
                break;
            case 1:
                return 4;
                break;
        }
    }
    else if (idx == 4)
    {
        switch (next)
        {
            case 1:
                return 3;
                break;
            case 3:
                return 3;
                break;
            case 2:
                return 4;
                break;
        }
    }

    return 2;
}

void dynamic()
{
    fill_n(&dp[0][0][0], 100000 * 5 * 5, 1e7);
    dp[0][steps[0]][0] = 2;
    dp[0][0][steps[0]] = 2;

    for (int k = 1; k < steps.size(); k++)
    {
        int next = steps[k];

        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
            {
                if (!dp[k][i][j])
                    continue;
                
                dp[k][next][j] = min(dp[k][next][j], dp[k-1][i][j] + cost(i, next));
                dp[k][i][next] = min(dp[k][i][next], dp[k-1][i][j] + cost(j, next));
            }
    }
}

int ans = 1e7;
void find_answer()
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            ans = min(ans, dp[steps.size()-1][i][j]);
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    dynamic();
    find_answer();
}