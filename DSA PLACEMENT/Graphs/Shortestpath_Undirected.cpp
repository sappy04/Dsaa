#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_path(vector<vector<int>> edges, int nodes, int edge, int src, int dest)
{
    unordered_map<int, list<int>> adj; // Adjacency list bana liya
    for (int i = 0; i < edges.size(); i++)
    {                            // Sare edges k nodes ko store karenge from edges structure
        int node1 = edges[i][0]; // edges[i].first ko edges[i][0] se replace karna pada
        int node2 = edges[i][1]; // edges[i].second ko edges[i][1] se replace karna pada

        // For directed graph
        adj[node1].push_back(node2); // Adjlist mai daal diya
        adj[node2].push_back(node1); // Adjlist mai daal diya
    }

    // do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
        int front = q.front(); // src ko nikal liya
        q.pop();

        // abhi src k neighbours ko dalunga
        for (auto neighbours : adj[front]) // neighbours of front from adj
        {
            if (!visited[neighbours]) // agar neigh visitd nahi hua to
            {
                visited[neighbours] = true; // mark karo true and visited by adding their parents too
                parent[neighbours] = front;
                q.push(neighbours); // phir neigh ko daal do queue mai
            }
        }
    }

    // prepare shortest ans
    vector<int> ans;
    int currentnode = dest;     // destination ko pakra
    ans.push_back(currentnode); // usko ans mai daala
    while (currentnode != src)
    {
        currentnode = parent[currentnode]; // desti k parent ko pakra
        ans.push_back(currentnode);        // add kar diya parent ko ans mai
    }
    reverse(ans.begin(), ans.end()); // reverse kar diya
    return ans;
}

int main()
{
    int nodes = 8;
    int edge = 9;
    vector<vector<int>> edges = {
        {1, 2}, {1, 3}, {1, 4}, {2, 5}, {5, 8}, {3, 8}, {4, 6}, {6, 7}, {7, 8}};

    int src = 1, dest = 8;
    vector<int> result = shortest_path(edges, nodes, edge, src, dest);

    cout << "Shortest path from " << src << " to " << dest << " is: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
