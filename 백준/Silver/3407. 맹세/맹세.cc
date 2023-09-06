//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T;
string check;
string atom[114] = { "h", "li", "na", "k", "rb", "cs", "fr", "be", "mg", "ca", "sr", "ba", "ra", "sc", "y", "ti", "zr", "hf", "rf", "la", "ac", "v", "nb", "ta", "db", "ce", "th", "cr", "mo", "w", "sg", "pr", "pa", "mn", "tc", "re", "bh", "nd", "u", "fe", "ru", "os", "hs", "pm", "np", "co", "rh", "ir", "mt", "sm", "pu", "ni", "pd", "pt", "ds", "eu", "am", "cu", "ag" ,"au", "rg", "gd", "cm", "zn", "cd", "hg", "cn", "tb", "bk", "b", "al", "ga", "in", "tl", "dy", "cf", "c", "si", "ge", "sn", "pb", "fl", "ho", "es", "n", "p", "as", "sb", "bi", "er", "fm", "o", "s", "se", "te", "po", "lv", "tm", "md", "f", "cl", "br", "i", "at", "yb", "no", "he", "ne", "ar", "kr", "xe", "rn","lu", "lr" };

bool visited[50000];

void bfs(int x, int len)
{
    memset(visited, 0, sizeof(visited));
    bool flag = 0;
    queue<int> que;
    que.push(x);
    visited[x] = 1;

    while (!que.empty())
    {
        int f = que.front();
        que.pop();

        if (f == len)
        {
            flag = 1;
            break;
        }

        string tmp, tmp2;
        tmp += check[f];
        tmp2 = tmp;
        tmp2 += check[f+1];

        for (int i = 0; i < 114; i++)
        {
            if (tmp == atom[i] && !visited[f+1])
            {
                visited[f+1] = 1;
                que.push(f+1);
            }
            if (tmp2 == atom[i] && !visited[f+2])
            {
                visited[f+2] = 1;
                que.push(f+2);
            }
        }
    }

    if (flag)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> check;
        bfs(0, check.size());
    }
}