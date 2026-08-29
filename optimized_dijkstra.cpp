#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[105];
int dis[105];
bool visited;

void optimized_dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty())
    {
        auto parent = pq.top();
        pq.pop();

        int parent_dis = parent.first;
        int parent_node = parent.second;

        for (auto child : adj_list[parent_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if (parent_dis + child_dis < dis[child_node])
            {
                dis[child_node] = parent_dis + child_dis;
                pq.push({dis[child_node], child_node});
                
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    optimized_dijkstra(0);

    for (int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << endl;

    return 0;
}