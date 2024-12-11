#include <bits/stdc++.h>
using namespace std;
class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj; // node k coresponding neighbour,dist

    void addedge(int node1, int node2, int weight)
    {
        pair<int, int> p = make_pair(node2, weight); // neighbour+weight
        adj[node1].push_back(p);                     // adj mai daal diya node 1 k respect mai
    }
    void printadj()
    {
        for (auto i : adj)
        {
            cout << i.first << " - > ";
            for (auto j : i.second)
            {
                cout << "( " << j.first << " , " << j.second << " )";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &stacky)
    {
        visited[node] = true;            // jo bhi node aya usko visited mark kiya
        for (auto neighbour : adj[node]) // node k saare neighbour aagaye
        {
            if (!visited[neighbour.first]) // neighbour agar visited nahi hai tabhi dfs call karo
            {
                dfs(neighbour.first, visited, stacky); // dfs call hoga end mai jab return hoga to saare stack mai dal jayenge
            }
        }
        stacky.push(node);
    }
    void getshortestpath(int src, vector<int> &dist, stack<int> &stacky)
    {
        dist[src] = 0;
        while (!stacky.empty()) // jab tak mera stack empty nahi ho raha
        {
            int top = stacky.top(); // top wala element nikalo
            stacky.pop();

            if (dist[top] != INT_MAX) // agar mera top eleemnt ka distance infinity nahi hai
            {
                for (auto neigh : adj[top]) // us element k saare neighbour nikalo aur ek ek karke in neighbour ka processing karo
                {
                    if (dist[top] + neigh.second < dist[neigh.first]) // dist[neigh]->first hamesha inifinity hai...to abhi 1 ka dist 0 hai aur 2 ka dist 2 hai to (0+2=) 2< infi to 
                    {
                        dist[neigh.first] = dist[top] + neigh.second; // distance ko update kar diya
                    }
                }
            }//agar infinity hua to maa chudaye
        }
    }
};
int main()
{
    graph g;
    g.addedge(0, 1, 5);
    g.addedge(0, 2, 3);
    g.addedge(1, 2, 2);
    g.addedge(1, 3, 6);
    g.addedge(2, 3, 7);
    g.addedge(2, 4, 4);
    g.addedge(2, 5, 2);
    g.addedge(3, 4, -1);
    g.addedge(4, 5, -2);

    g.printadj();
    // topological sort
    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> stacky;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) // agar mera node visisted nahi hai phir karo usse visisted by dfs
        {
            g.dfs(i, visited, stacky);
        }
    }



    int src = 1;         // 1 ko src mana
    vector<int> dist(n); // vector banaya for distance of size no.of node

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX; // infinity se mark kar diya saare slots ko distance vector mai
    }



    g.getshortestpath(src, dist, stacky);
    cout << "The answer is: " << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
