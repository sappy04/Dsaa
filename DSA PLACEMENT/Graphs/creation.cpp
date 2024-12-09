#include <bits/stdc++.h>
using namespace std;

class graph//mere pass pehle se hi graph ready hai mai just graph dekhe uska adjancecy list bana raha
{
public:
    unordered_map<int, list<int>> mapping;//adjancency list k liye map liya

    void addedge(int node1, int node2, int direct) // direct==directed(1)/undirected(0),edge add karenge bc 2 nodes k beech mai hi na!!
    {
        // create edge between nodes
        mapping[node1].push_back(node2);//ya pe mai nodes ka pair banaya..node1 k list mai nide 2 add ho gaya hai

        if (direct == 0) // undirected graph hai to vice versa mapping bhi ho jayega
        {
            mapping[node2].push_back(node1);//undirected hai to node2 k respect mai bhi list create hogaya for node2 list mai node 1 hai
        }
    }

    void printit()
    {
        for (unordered_map<int, list<int>>::iterator it = mapping.begin(); it != mapping.end(); ++it) // iterate through the unordered map
        {
            cout << it->first << " -> "; // print the key (node)

            for (list<int>::iterator lit = it->second.begin(); lit != it->second.end(); ++lit) // iterate through the adjacency list
            {
                cout << *lit << " "; // print each adjacent node
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    bool isDirected;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> isDirected;

    graph g; // Create a graph

    for (int i = 0; i < m; i++)
    {
        int node1, node2;
        cout << "Enter edge (node1 node2): ";
        cin >> node1 >> node2;
        g.addedge(node1, node2, isDirected); // Add edge based on the graph's directed/undirected nature
    }

    g.printit(); // Print the adjacency list
    return 0;
}

// // Enter the number of nodes: 5
// // Enter the number of edges: 6
// // Is the graph directed? (1 for Yes, 0 for No): 0
// // Enter edge (node1 node2): 0 1
// // Enter edge (node1 node2): 1 2
// // Enter edge (node1 node2): 2 3
// // Enter edge (node1 node2): 3 1
// // Enter edge (node1 node2): 3 4
// // Enter edge (node1 node2): 0 4
// // 4 -> 3 0
// // 0 -> 1 4
// // 1 -> 0 2 3
// // 2 -> 1 3
// // 3 -> 2 1 4



// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> printadjacencylist(int n, int m, vector<vector<int>> &edges) //n is nodes and m is edges edges is map
// {
//     // Create an adjacency list using a vector of vectors
//     vector<vector<int>> adjlist(n);//map bana liya to represnt kis kis k beech mai edges hai

//     for (int i = 0; i < m; i++)//saare edges ko input lo
//     {
//         int u = edges[i][0]; // Starting node of edge
//         int v = edges[i][1]; // Ending node of edge

//         adjlist[u].push_back(v); // Add v to the adjacency list of u
//         adjlist[v].push_back(u); // Add u to the adjacency list of v (since undirected)
//     }

//     // The adjacency list is now complete
//     return adjlist;
// }

// int main() 
// {
//     int n, m;
//     cout << "Enter the number of nodes: ";
//     cin >> n;
//     cout << "Enter the number of edges: ";
//     cin >> m;

//     vector<vector<int>> edges(m, vector<int>(2));
//     cout << "Enter the edges (node1 node2):" << endl;
//     for (int i = 0; i < m; i++) 
//     {
//         cin >> edges[i][0] >> edges[i][1];//edges mera map hai jismai pehla wala bhi node hai dusra wala bhi node hai..dono nodo k beech edge hai 
//     }

//     vector<vector<int>> adjlist = printadjacencylist(n, m, edges);

//     // Print the adjacency list
//     cout << "The adjacency list is:" << endl;
//     for (int i = 0; i < adjlist.size(); i++) 
//     {
//         cout << i << " -> ";
//         for (int j = 0; j < adjlist[i].size(); j++) 
//         {
//             cout << adjlist[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4
// The adjacency list is:
// 0 -> 1 4
// 1 -> 0 2 3
// 2 -> 1 3
// 3 -> 2 1 4
// 4 -> 3 0