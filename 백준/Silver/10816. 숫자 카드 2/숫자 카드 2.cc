// Silver 4. Digit Card 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;


int main()
{
    cin >> N;

    vector<int> card(N, 0);

    for (int i = 0; i < N; i++)
        cin >> card[i];
    
    sort(card.begin(), card.end());
    
    cin >> M;

    vector<int> check(M, 0);
    vector<int> res(20000001, 0);

    for (int i = 0; i < M; i++)
        cin >> check[i];
    
    for (int i = 0; i < N; i++)
        res[card[i]+10000000]++;
    
    for (int i = 0; i < M; i++)
        cout << res[check[i]+10000000] << ' ';
}