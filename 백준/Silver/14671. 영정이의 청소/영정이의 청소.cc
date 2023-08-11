// 8ms

#include <iostream>
#include <stack>

using namespace std;

int N, M, K;
bool visited[2][2];
stack<pair<int, int>> stk;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    
    while (K--)
    {
        int x, y;
        
        cin >> x >> y;

        visited[x%2][y%2] = 1;
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (!visited[i][j])
            {
                cout << "NO";
                return 0;
            }
    
    cout << "YES";
}