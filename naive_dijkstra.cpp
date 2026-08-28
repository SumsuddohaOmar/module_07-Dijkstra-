#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj_list[105];
int dis[105];

void naive_dijkstra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;

    while (!q.empty())
    {
        auto parent = q.front();
        q.pop();
        int parent_node = parent.first;
        int parent_dis = parent.second;

        for(auto child : adj_list[parent_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if(parent_dis + child_dis < dis[child_node])
            {
                dis[child_node] = parent_dis + child_dis;
                q.push({child_node, dis[child_node]});
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
        int a, b , c;
        cin >> a >> b>> c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    naive_dijkstra(0);

    for (int i = 0; i < n; i++)
        cout << i << " -> " << dis[i] << endl;
    
    return 0;
}