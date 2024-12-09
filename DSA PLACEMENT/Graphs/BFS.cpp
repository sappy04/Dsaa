#include <bits/stdc++.h>
using namespace std;

void prepare_adjlist(unordered_map<int, list<int>>& adjlist, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        // nodes pakra
        int u = edges[i].first;  // pehla node jisnke beech edge hai
        int v = edges[i].second; // dusra node

        // mapping create kar diya for undirected
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

void printadj_list(unordered_map<int, list<int>>& adjlist)
{
    for (unordered_map<int, list<int>>::iterator it = adjlist.begin(); it != adjlist.end(); ++it) 
    {
        cout << it->first << "->";
        for (list<int>::iterator lit = it->second.begin(); lit != it->second.end(); ++lit)
        {
            cout << *lit << " "; // Dereference the iterator to access the value
        }
        cout << endl;
    }
}

void bfs(unordered_map<int, list<int>>& adjlist, unordered_map<int, bool>& visited, vector<int>& ans, int node)
{
    queue<int> q;      // queue to chahiye hi
    q.push(node);      // starting node bhej diya queue mai
    visited[node] = 1; // jis node ko queue mai daala usko mai 1 mark kar diya

    while (!q.empty()) // jab tak queue khali nahi hota karte raho
    {
        int frontnode = q.front(); // queue ka pehla value le liya front node mai
        q.pop();                   // hata diya element q se
        ans.push_back(frontnode);  // jab maine q se hata hi diya tabh daalo na bc ans mai

        // abhi saare uske neighbour nodes ko daalna hai
        for (list<int>::iterator lit = adjlist[frontnode].begin(); lit != adjlist[frontnode].end(); ++lit) // saare neighbouring nodes ko dekh raha
        {
            if (!visited[*lit]) // agar mera neighbouring node visited nahi hai
            {
                q.push(*lit);      // queue mai daal diya
                visited[*lit] = 1; // mark kar do ki haa visited hogaya
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) // bfs karne k liye kya kya darkar hai mujhe
{
    unordered_map<int, list<int>> adjlist; // adjacency list banaya
    vector<int> ans;                       // ans store karne k liye vector banake rakha
    unordered_map<int, bool> visited;      // bfs k time kaam ayega agar visited raha to queue mai include nahi hoga

    prepare_adjlist(adjlist, edges);
    printadj_list(adjlist);

    // Initialize all nodes as unvisited
    for (int i = 0; i < vertex; ++i)
    {
        visited[i] = false; // Ensure that visited map is initialized
    }

    for (int i = 0; i < vertex; ++i) // tree ko upar se neeche tak pura nangna dekh raha hoon
    {
        if (!visited[i]) // agar node visited nahi hai
        { 
            bfs(adjlist, visited, ans, i); // bfs dekhne k liye mujhe adjlist dekhna padhega visited hai ki nahi aur nodes aur ans store karne k liye ans bhejna padhega aur i yaha pe node hai jahan se start ho raha
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    vector<pair<int, int>> edges;
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> bfs_result = BFS(n, edges); // perform BFS

    cout << "BFS Traversal Result: ";
    for (int i = 0; i < bfs_result.size(); ++i)
    {
        cout << bfs_result[i] << " ";
    }
    cout << endl;

    return 0;
}
