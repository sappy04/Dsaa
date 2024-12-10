#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalsort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj; // Adjacency list bana liya
    for (int i = 0; i < e; i++)
    { // Sare edges k nodes ko store karenge from edges structure
        int node1 = edges[i][0];
        int node2 = edges[i][1];

        // For directed graph
        adj[node1].push_back(node2); // Adjlist mai daal diya
    }

    // Find all indegree
    vector<int> indegree(v + 1, 0); // (v + 1) size ka indegree ka vector bnaya with zero initialised to all
    for (auto i : adj) // adj ek list hai na node->node1...i hai ye node->node1 k line pe targeted..node 1 pe hi na sab invalues ghus raha hai as it directed
    {
        for (auto j : i.second)//ye uske neighbours pe target hai ..one by one neighbours ayenge ispe
        {
            indegree[j]++;
        }
    }

    // 0 indegree wale ko min-heap mai push karo
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 1; i <= v; i++) // Node numbering starts from 1
    {
        if (indegree[i] == 0)
        {
            minHeap.push(i);
        }
    }

    // Do BFS
    vector<int> ans; // ans banake rakha for storing ans from minHeap
    while (!minHeap.empty())
    {
        int front = minHeap.top(); // top ko pehle value pe target kar diya
        minHeap.pop();             // hataya element ko
        ans.push_back(front);      // ans mai daal diya

        // Abhi neighbours k indegree ko update karna hai
        for (auto neigh : adj[front]) // front k saare neighbours aagaye
        {
            indegree[neigh]--; // kama diya neighbours k value ko
            // Kamane k immediate baad check karke daalo min-heap mai
            if (indegree[neigh] == 0)
            {
                minHeap.push(neigh); // min-heap mai daal diya
            }
        }
    }

    return ans; // Final sorted list return
}

int main()
{
    int v = 5; // Number of vertices
    int e = 5; // Number of edges

    // Edge list representation of graph
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 5},
        {3, 5},
        {5, 4}};

    vector<int> result = topologicalsort(edges, v, e);

    cout << "Topological Order: ";
    for (auto node : result)
    {
        cout << node << " ";
    }

    return 0;
}
