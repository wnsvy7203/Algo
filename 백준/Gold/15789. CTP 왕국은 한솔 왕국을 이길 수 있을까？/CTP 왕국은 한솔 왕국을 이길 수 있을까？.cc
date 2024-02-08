// 44ms

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, C, H, K;
int par[100001], ally[100001];

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
    // 이미 한 집합에 묶여 있다면 한 번 더 수행할 필요가 없다.
    else if (x == y)
        return;

    par[y] = x;
    // 집합을 합칠 때, ally의 수를 따로 합쳐서 저장해준다.
    ally[x] += ally[y];
}

void init()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        par[i] = i;
        // 동맹이 없는 왕국의 힘은 1이다.
        ally[i] = 1;
    }
}

priority_queue<int> pq;
void settings()
{
    while (M--)
    {
        int X, Y;
        cin >> X >> Y;
        union_sets(X, Y);
    }

    cin >> C >> H >> K;
    C = find(C);
    H = find(H);

    // C와 이미 동맹이거나, H와 동맹을 맺은 국가와는 동맹을 맺을 수 없다.
    for (int i = 1; i <= N; i++)
        if (par[i] == i && i != C && i != H)
            pq.push(ally[i]);

    while (K--)
    {
        int t = pq.top();
        pq.pop();

        ally[C] += t;
    }
}

void find_answer()
{
    cout << ally[C];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();
    settings();
    find_answer();
}