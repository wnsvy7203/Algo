//

#include <iostream>
#include <algorithm>

using namespace std;


int N;
int fst, lst, dif;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> lst;
        if (i)
        {
            if (lst < fst)
                fst = lst;
        }
        else
            fst = lst;

        dif = max(dif, lst-fst);
    }

    cout << dif;
}