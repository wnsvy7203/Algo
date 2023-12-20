#include <iostream>

using namespace std;

int S, M;
int N = 1023;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> M;
    if (S <= N)
    {
        // S가 N보다 작거나 같으면 반드시 필요없으므로 No thanks 출력 후 바로 return
        cout << "No thanks";
        return 0;
    }

    // S가 N보다 커야 이 단계로 넘어오고, 한 번 빼준다.
    S -= N;
    bool flag = 1;
    for (int i = 0; i <= 10; i++)
        // S에 i가 포함되어 있고, M에 i가 포함되어 있지 않으면 flag = 0;
        if ((S & (1 << i)) && !(M & (1 << i)))
            flag = 0;

    cout << (flag ? "Thanks" : "Impossible");

}