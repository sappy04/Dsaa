// //dfs k through kiya hua hai

// #include <bits/stdc++.h>
// using namespace std;

// // Function to detect cycle using DFS
// bool iscycledfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj)
// {
//     visited[node] = true;      // Jo node aya pehle usko visited mark krdo
//     dfsvisited[node] = true;   // Same for dfsvisited

//     for (auto i : adj[node])   // Saare neighbours le raha mai src node ka
//     {
//         if (!visited[i])       // Agar mera node ka neighbour visited nahi hai tab usko mark kaar do by recursive call
//         {
//             bool furtherprocessing = iscycledfs(i, visited, dfsvisited, adj); // Neighbour nodes k processing k liye recurssive call
//             if (furtherprocessing)
//             {
//                 return true;   // Haa visited hai aage recursive call jaa sakta hai
//             }
//         }
//         else if (dfsvisited[i]) // Matlab mera neighbournode visited hai to abhi dfsvisited waale ko bhi check kar leta hoon
//         {
//             return true;       // Cycle present hai
//         }
//     }
//     dfsvisited[node] = false;  // Jab uske neeche aur call nahi hai jab return ho raha hai
//     return false;              // Abhi tak kuch nahi hua to cycle nahi hai
// }

// // Function to detect cycle in the graph
// int detectcycle(int n, vector<pair<int, int>> &edges)
// {
//     unordered_map<int, list<int>> adj; // Adjacency list bana liya
//     for (int i = 0; i < edges.size(); i++)
//     { // Sare edges k nodes ko store karenge from edges structure
//         int node1 = edges[i].first;
//         int node2 = edges[i].second;

//         // For directed graph
//         adj[node1].push_back(node2); // Adjlist mai daal diya
//     }

//     unordered_map<int, bool> visited;    // Visited tracker globally declared
//     unordered_map<int, bool> dfsvisited; // Visited tracker globally declared

//     // To handle disconnected parts
//     for (int i = 1; i <= n; i++)
//     {
//         if (!visited[i])
//         {                                                       // Agar mera node visited nahi hai
//             bool ans = iscycledfs(i, visited, dfsvisited, adj); // Usko dfs k through check karo kya wo cyclic hai
//             if (ans)
//             {
//                 return true; // Cycle hai
//             }
//         }
//     }
//     return false; // Yaha tak agaya matlab cycle nahi hai
// }

// int main()
// {
//     int n = 8; // Number of nodes
//     vector<pair<int, int>> edges = {
//         {1, 2},
//         {2, 3},
//         {2, 4},
//         {3, 7},
//         {3, 8},
//         {8, 7},
//         {5, 6},
//         {6, 4},
//         {4, 5}}; // Cycle present in graph

//     if (detectcycle(n, edges))
//     {
//         cout << "Cycle detected in the graph.\n";
//     }
//     else
//     {
//         cout << "No cycle detected in the graph.\n";
//     }

//     return 0;
// }


//bfs k through kiya hua hai
//logic:ki agar mai kahn algo use karu for topological order...hoga ki agar mera graph kahn algo satisfy kar raha then graph mai cycle nahi hai par agar nahi kara then to cycle hai as kahn algo only works for directed acyclic graph


#include <bits/stdc++.h>
using namespace std;

int detectcycle(int n, vector<pair<int, int>> &edges)
{
    // Pura kahn algo daala pehle
    unordered_map<int, list<int>> adj; // Adjacency list bana liya
    for (int i = 0; i < edges.size(); i++)
    { // Sare edges k nodes ko store karenge from edges structure
        int node1 = edges[i].first;
        int node2 = edges[i].second;

        // For directed graph
        adj[node1].push_back(node2); // Adjlist mai daal diya
    }

    // Find all indegree
    vector<int> indegree(n + 1, 0); // (n + 1) size ka indegree ka vector bnaya with zero initialised to all
    for (auto i : adj)              // adj ek list hai na node->node1...i hai ye node->node1 k line pe targeted..node 1 pe hi na sab invalues ghus raha hai as it directed
    {
        for (auto j : i.second) // ye uske neighbours pe target hai ..one by one neighbours ayenge ispe
        {
            indegree[j]++;
        }
    }

    // 0 indegree wale ko min-heap mai push karo
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 1; i <= n; i++) // Node numbering starts from 1
    {
        if (indegree[i] == 0)
        {
            minHeap.push(i);
        }
    }

    // Do BFS
    int cnt = 0; // topological sort hoga to count = number of nodes hoga
    while (!minHeap.empty())
    {
        int front = minHeap.top(); // top ko pehle value pe target kar diya
        minHeap.pop();             // hataya element ko
        cnt++;

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

    if (cnt == n)
    {
        return false; // Count to equal agaya mere no.of nodes k sath to cycle nahi hai
    }
    else
    {
        return true; // Cycle hai as count equal nahi hai
    }
}

int main()
{
    int n = 8; // Number of nodes
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {2, 4},
        {3, 7},
        {3, 8},
        {8, 7},
        {5, 6},
        {4, 6},
        {4, 5}}; // Cycle present in graph

    if (detectcycle(n, edges))
    {
        cout << "Cycle detected in the graph.\n";
    }
    else
    {
        cout << "No cycle detected in the graph.\n";
    }

    return 0;
}
