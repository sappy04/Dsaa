#include <bits/stdc++.h>
using namespace std;

bool iscyclebfs(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    unordered_map<int, int> parent; // Kis node ka kon parent hai track karne k liye
    parent[src] = -1;               // Source k parent ko -1 kar
    visited[src] = 1;               // Visited hogaya
    queue<int> q;
    q.push(src); // Q mai src node ko daal diya
    while (!q.empty())
    {
        int front = q.front(); // Q ka pehla eleemnt nikal liya
        q.pop();
        for (auto i : adj[front])
        { // Front k jitne neighbour hai sab nikal do
            if (visited[i] == true && i != parent[front])
            { // Cyclic ki condition
                return true;
            }
            else if (!visited[i])
            {                      // Agar cyclic nahi hai then
                q.push(i);         // Q mai push kar do
                visited[i] = 1;    // I ko visited mark kar do
                parent[i] = front; // Parent bhi set kar diya
            }
        }
    }
    return false; // Yaha tak agaya matlab koi cycle nahi hai
}

string cycledetection(vector<vector<int>> &edges, int n, int m)
{                                      // N is nodes M is edges
    unordered_map<int, list<int>> adj; // Adjacency list bana liya
    for (int i = 0; i < m; i++)
    { // Sare edges k nodes ko store karenge from edges structure
        int node1 = edges[i][0];
        int node2 = edges[i][1];

        // For undirected graph
        adj[node1].push_back(node2); // Adjlist mai daal diya
        adj[node2].push_back(node1); // Adjlist mai daal diya
    }

    unordered_map<int, bool> visited; // Visited tracker globally declared

    // To handle disconnected parts
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {                                           // Agar mera node visited nahi hai
            bool ans = iscyclebfs(i, visited, adj); // Usko bfs k through check karo kya wo cyclic hai by node visited hai ki nahi through adjacency
            if (ans == 1)
            {
                return "yes"; // Cycle hai
            }
        }
    }
    return "no"; // Yaha tak agaya matlab cycle nahi hai
}

int main()
{
    int n = 5; // Number of nodes
    int m = 5; // Number of edges
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1} // Input edges
    };

    string result = cycledetection(edges, n, m);
    cout << "Cycle detected: " << result << endl;

    return 0;
}
