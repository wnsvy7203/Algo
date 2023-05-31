// Silver 3. Finding Prime Numbers

#include <iostream>
#include <cmath>

using namespace std;

int M, N;

int main()
{
    cin >> M >> N;

    for (int i = M; i <= N; i++)
    {
        bool flag = 1;

        if (i == 1) flag = 0;
        else if (i == 2) flag = 1;
        else
            for (int j = 2; j < sqrt(i)+1; j++)
                if (!(i % j))
                {
                    flag = 0;
                    break;
                }

        if (flag)   cout << i << '\n';
    }
}