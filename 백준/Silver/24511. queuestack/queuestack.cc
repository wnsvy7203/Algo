// 188ms

#include <iostream>
#include <deque>

using namespace std;

int N, M;
int A[100001];

deque<int> deq;
int C[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    int num;
    
    for (int i = 0; i < N; i++)
    {
        cin >> num;

        if (!A[i])
            deq.push_back(num);
    }

    int zero = deq.size();

    cin >> M;

    while (M--)
    {
        cin >> num;

        deq.push_front(num);
        cout << deq.back() << ' ';
        deq.pop_back();
    }
}