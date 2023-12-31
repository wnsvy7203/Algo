// 0ms

// idea: 8개의 좌표를 vector 안에 다 넣고 idx 0 -> 1까지의 거리를 다익스트라로 구한다.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF 1e9

using namespace std;

int xs, ys, xe, ye;

vector<pair<int, int>> board;
void input()
{
    cin >> xs >> ys >> xe >> ye;
    board.push_back({xs, ys});
    board.push_back({xe, ye});

    for (int i = 0; i < 3; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        board.push_back({x1, y1});
        board.push_back({x2, y2});
    }
}

long long calculate_distance(int s, int e)
{
    return (long long) abs(board[s].first - board[e].first) + (long long) abs(board[s].second - board[e].second);
}

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
long long dist[8];
void dijkstra()
{
    for (int i = 1; i < 8; i++)
        dist[i] = LLONG_MAX;
    
    pq.push({0, 0});
    while (!pq.empty())
    {
        long long cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < cost)
            continue;
        
        for (int next_node = 0; next_node < 8; next_node++)
        {
            if (node == next_node)
                continue;
            
            long long next_cost = calculate_distance(node, next_node);
            
            if (node != 0 && !(node % 2) && node == next_node-1)
                next_cost = min(next_cost, 10LL);
            
            if (node != 1 && (node % 2) && node == next_node+1)
                next_cost = min(next_cost, 10LL);
            
            if (dist[next_node] > cost + next_cost)
            {
                dist[next_node] = cost + next_cost;
                pq.push({dist[next_node], next_node});
            }
        }
    }

    cout << dist[1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    dijkstra();
}