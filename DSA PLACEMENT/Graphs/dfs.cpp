#include <bits/stdc++.h>
using namespace std;

void depthfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component)
{
    component.push_back(node); // Pehla jo bhi node aya usko store karlo component mai
    visited[node] = true;      // Us node ko true mark do

    for (auto it = adj[node].begin(); it != adj[node].end(); ++it)
    { // Abhi jo adj list mai link hai components ka uska starting pe it target kar raha
        if (!visited[*it])
        { // Agar ye node visited nahi hai tabh isko dfs call karo
            depthfs(*it, visited, adj, component);
        }
    }
}

vector<vector<int>> dfs(int v, int e, vector<vector<int>> &edges)
{                                      // Edges mai mujhe node mil rahe 2 jisnke beech mai edge hai ye mera wo function hai jismai saare stuffs jo needed hai wo hai ismai
    unordered_map<int, list<int>> adj; // Adjacency list bana liya

    // Populate the adjacency list
    for (int i = 0; i < edges.size(); i++)
    {
        int node1 = edges[i][0];
        int node2 = edges[i][1];

        // For undirected graph
        adj[node1].push_back(node2); // adjlist mai daal diya
        adj[node2].push_back(node1); // adjlist mai daal diya
    }

    vector<vector<int>> ans;          // dfs ka ans store karne k liye
    unordered_map<int, bool> visited; // dfs k liye darkar padhega na

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {                                        // Agar mera node visited nahi hai
            vector<int> component;               // Component mai dfs store karo and ans mai daal do
            depthfs(i, visited, adj, component); // Uska dfs karo
            ans.push_back(component);
        }
    }
    return ans; // Return the final answer
}

int main()
{
    // Example usage
    int v = 5, e = 4;
    vector<vector<int>> edges = {{0, 2}, {2, 1}, {2, 4}, {4, 3}, {1, 3}};

    vector<vector<int>> result = dfs(v, e, edges);

    for (const auto &component : result)
    {
        for (int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
//0 2 1 3 4 